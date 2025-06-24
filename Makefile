# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dario <dario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 18:40:53 by dario             #+#    #+#              #
#    Updated: 2025/06/24 22:35:14 by dario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

MAKEFLAGS += --no-print-directory

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-g3
RM			=	rm -f

VALFLAGS	=	--tool=helgrind --tool=drd

# Libft
LIBFT		=	./libft/
LIBFT_LIB	=	$(LIBFT)libft.a
LIBS 		=	-lreadline -lncurses -ltermcap

DIR			=	srcs/
HDERS		=	minishell.h
SRC			=	main.c
BUILTINS	=	cd.c echo.c env.c exit.c export.c pwd.c unset.c
LEXER		=	utils.c token.c

SRCS		=	$(addprefix srcs/, $(SRC)) \
				$(addprefix srcs/builtins/, $(BUILTINS)) \
				$(addprefix srcs/lexer/, $(LEXER))

OBJS		=	$(SRCS:.c=.o)

# Colors
RST			=	\033[0m
RED			=	\033[1;31m
BLUE		=	\033[1;34m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m

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
	@echo -e "$(BLUE)Compiling $(NAME)...$(RST)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB) -lreadline
	@echo -e "$(BG_GREEN)$(NAME) compiled!$(BG_RST)"

$(LIBFT_LIB):
	@make -C $(LIBFT) -f Makefile

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT) clean
	@echo -e "$(BG_GREEN)$(NAME) objs cleaned$(BG_RST)"

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@echo -e "$(BG_GREEN)$(NAME) fully cleaned$(BG_RST)"

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
