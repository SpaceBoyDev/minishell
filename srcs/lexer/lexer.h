/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:46:48 by marcolop          #+#    #+#             */
/*   Updated: 2025/06/28 15:46:48 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_op
{
	STR,
	PIPE,
	IN,
	OUT,
	APPEND,
	HEREDOC,
}	t_op;

typedef struct s_token
{
	t_op			type;
	char			*str;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	*infile;
	char	*outfile;
	t_op	in;
	t_op	out;
}	t_cmd;

// utils.c
int				check_quotes(char *str);
void			print_token(t_token *token);
void			print_tokens(t_token *token);
int				is_separator(char c);

// token.c
t_token			*tokenize(char *input);
t_token			*create_token(char *str, int *i);
char			*token_str(char *str, int *i);
t_op	token_type(char *str, int *i);

// var_expansion.c
char			*expand(char *str);
int				is_var_char(char c);

#endif
