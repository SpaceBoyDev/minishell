# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dario <dario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 18:40:53 by dario             #+#    #+#              #
#    Updated: 2025/06/29 20:36:11 by dario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

MAKEFLAGS	+=	--no-print-directory

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-g3
RM			=	rm -f

VALFLAGS	=	--tool=helgrind --tool=drd

# Libft
LIBFT		=	./libft/
LIBFT_LIB	=	$(LIBFT)libft.a
LIBS 		=	-lreadline -lncurses -ltermcap

DIR			=	srcs/
HDERS		=	srcs/minishell.h
SRC			=	main.c
LEXER		=	utils.c token.c cmd.c
EXECUTE		=	run.c
BUILTINS	=	builtins_utils.c cd.c echo.c env.c exit.c export.c pwd.c unset.c

SRCS		=	$(addprefix srcs/, $(SRC)) \
				$(addprefix srcs/builtins/, $(BUILTINS)) \
				$(addprefix srcs/lexer/, $(LEXER)) \
				$(addprefix srcs/execute/, $(EXECUTE))

OBJS		=	$(SRCS:.c=.o)

define SIGNATURE
                                                         ,
                                                      \  :  /
                                                   `. __/ \__ .'
                               | |                 _ _\     /_ _                                         
  _ __ ___   __ _ _ __ ___ ___ | | ___  _ __          /_   _\                                    
 | '_ ` _ \ / _` | '__/ __/ _ \| |/ _ \| '_ \       .'  \ /  `.                                              
 | | | | | | (_| | | | (_| (_) | | (_) | |_) |        /  :  \     _       _     _          _ _ 
 |_| |_| |_|\__,_|_|  \___\___/|_|\___/| .__/  ______    '       (_)     (_)   | |        | | |
                     _| |_             | |    |______|  _ __ ___  _ _ __  _ ___| |__   ___| | |
      _             |_   _|            |_|  _  ______  | '_ ` _ \| | '_ \| / __| '_ \ / _ \ | |
     | |              |_|              | | (_)|______| | | | | | | | | | | \__ \ | | |  __/ | |
   __| | __ _ _ __ _ __ ___   __ _ _ __| |_ _          |_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|
  / _` |/ _` | '__| '_ ` _ \ / _` | '__| __| |                         ╱|、                                   
 | (_| | (_| | |  | | | | | | (_| | |  | |_| |                        (`O -  7                                             
  \__,_|\__,_|_|  |_| |_| |_|\__,_|_|   \__|_|                          |、⁻〵   
                                                                        じしˍ,)ノ   
endef
export SIGNATURE

# Colors
RST			=	\033[0m
RED			=	\033[1;31m
BLUE		=	\033[1;34m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
MAGENTA		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m

# Background colors
BG_RST		=	\033[0m
BG_RED		=	\033[41m
BG_GREEN	=	\033[42m
BG_YELLOW	=	\033[43m
BG_BLUE		=	\033[44m
BG_MAGENTA	=	\033[45m
BG_CYAN		=	\033[46m
BG_WHITE	=	\033[47m

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB) -lreadline
	@echo -e "\n$(BG_GREEN)$(NAME) compiled!$(BG_RST)"
	@echo -e "$(MAGENTA)$$SIGNATURE$(RST)"

$(LIBFT_LIB):
	@echo -e "$(BG_BLUE)Compiling libft...$(RST)"
	@make -C $(LIBFT) -f Makefile
	@echo -e "$(BG_BLUE)Compiling $(NAME)...$(RST)"

%.o: %.c
	@printf "$(MAGENTA)Compiling $< ✅$(RST)\033[0K\r"; $(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -e "$(BG_BLUE)Cleaning...$(BG_RST)"
	@$(RM) $(OBJS)
	@make -C $(LIBFT) clean
	@echo -e "$(CYAN)libft objs cleaned!$(BG_RST)🧹"
	@echo -e "$(CYAN)$(NAME) objs cleaned!$(BG_RST)🧹"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@echo -e "$(CYAN)$(NAME) fully cleaned!$(BG_RST)🧹"
	@echo -e "$(BG_GREEN)All cleaned!$(BG_RST)"

re: fclean all

norme:
	@echo -e "$(BG_CYAN)SOURCES$(BG_RST)"
	@for file in $(SRCS); do \
		norminette $$file | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo -e "$(GREEN)$$file: OK!$(RST)"; \
		else \
			echo -e "$(RED)"; \
			norminette $$file; \
			echo -e "$(RST)"; \
		fi \
	done
	@echo -e "$(BG_CYAN)HEADERS$(BG_RST)"
	@for header in $(HDERS); do \
		norminette $$header | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo -e "$(GREEN)$$header: OK!$(RST)"; \
		else \
			echo -e "$(RED)"; \
			norminette $$header; \
			echo -e "$(RST)"; \
		fi \
	done

.PHONY: all clean fclean re
