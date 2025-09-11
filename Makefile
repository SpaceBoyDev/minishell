# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dario <dario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 18:40:53 by dario             #+#    #+#              #
#    Updated: 2025/09/11 19:56:00 by dario            ###   ########.fr        #
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

BUILTINS	=	builtins_utils.c cd.c echo.c env.c exit.c export.c pwd.c unset.c
EXECUTE		=	exec.c pipeline.c run.c shlvl.c
HEREDOC		=	heredoc.c
LEXER		=	utils.c token.c cmd.c cmd_utils.c token_str.c var_expansion.c nbr_to_str.c
SIGNALS		=	signal_handling.c
TESTS		=	test.c
UTILS		=	main_utils.c shell_utils.c error_handling.c

SRCS		=	$(addprefix srcs/, $(SRC)) \
				$(addprefix srcs/builtins/, $(BUILTINS)) \
				$(addprefix srcs/execute/, $(EXECUTE)) \
				$(addprefix srcs/heredoc/, $(HEREDOC)) \
				$(addprefix srcs/lexer/, $(LEXER)) \
				$(addprefix srcs/signals/, $(SIGNALS)) \
				$(addprefix srcs/tester/, $(TESTS)) \
				$(addprefix srcs/utils/, $(UTILS))

OBJS		=	$(SRCS:.c=.o)

define SIGNATURE
                                                         ,
                                                      \  :  /
                                _                  `. __/ \__ .'
                               | |                 _ _\     /_ _
  _ __ ___   __ _ _ __ ___ ___ | | ___  _ __          /_   _\ 
 | '_ ` _ \ / _` | '__/ __/ _ \| |/ _ \| '_ \       .'  \ /  `.
 | | | | | | (_| | | | (_| (_) | | (_) | |_) |        /  :  \     _       _     _          _ _ 
 |_| |_| |_|\__,_|_|  \___\___/|_|\___/| .__/  ______    '       (_)     (_)   | |        | | |
                     _| |_             | |    |______|  _ __ ___  _ _ __  _ ___| |__   ___| | |
      _             |_   _|            |_|  _  ______  | '_ ` _ \| | '_ \| / __| '_ \ / _ \ | |
     | |              |_|              | | (_)|______| | | | | | | | | | | \__ \ | | |  __/ | |
   __| | __ _ _ __ _ __ ___   __ _ _ __| |_ _          |_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|
  / _` |/ _` | '__| '_ ` _ \ / _` | '__| __| |
 | (_| | (_| | |  | | | | | | (_| | |  | |_| |
  \__,_|\__,_|_|  |_| |_| |_|\__,_|_|   \__|_|

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
	@printf "$(MAGENTA)All $(NAME) source files compiled ✅$(RST)\033[0K\r"
	@echo "\n$(BG_GREEN)$(NAME) compiled!$(BG_RST)"
	@echo "$(MAGENTA)$$SIGNATURE$(RST)"

$(LIBFT_LIB):
	@echo "$(BG_BLUE)Compiling libft...$(RST)"
	@make -C $(LIBFT) -f Makefile
	@echo "$(BG_BLUE)Compiling $(NAME)...$(RST)"

%.o: %.c
	@printf "$(MAGENTA)Compiling $< ✅$(RST)\033[0K\r"; $(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BG_BLUE)Cleaning...$(BG_RST)"
	@$(RM) $(OBJS)
	@make -C $(LIBFT) clean
	@echo "$(CYAN)libft objs cleaned!$(BG_RST)🧹"
	@echo "$(CYAN)$(NAME) objs cleaned!$(BG_RST)🧹"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(CYAN)$(NAME) fully cleaned!$(BG_RST)🧹"
	@echo "$(BG_GREEN)All cleaned!$(BG_RST)"

re: fclean all

norme:
	@echo "$(BG_CYAN)SOURCES$(BG_RST)"
	@for file in $(SRCS); do \
		norminette $$file | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$file: OK!$(RST)"; \
		else \
			echo "$(RED)"; \
			norminette $$file; \
			echo "$(RST)"; \
		fi \
	done
	@echo "$(BG_CYAN)HEADERS$(BG_RST)"
	@for header in $(HDERS); do \
		norminette $$header | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$header: OK!$(RST)"; \
		else \
			echo "$(RED)"; \
			norminette $$header; \
			echo "$(RST)"; \
		fi \
	done

.PHONY: all clean fclean re
