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

#include <sys/types.h>
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
	char			*cmd;
	char			**args;
	char			*infile;
	char			*outfile;
	t_op			in_op;
	t_op			out_op;
	int				in_fd;
	int				out_fd;
	pid_t			pid;
	struct s_cmd	*next;
}	t_cmd;

// utils.c
int				check_quotes(char *str);
void			print_token(t_token *token);
void			print_tokens(t_token *token);
int				is_separator(char c);
void			print_cmd(t_cmd	*cmd);
void			print_cmds(t_cmd	*cmd);

// token.c
t_token			*tokenize(char *input);
t_token			*create_token(char *str, int *i);
char			*token_str(char *str, int *i);
t_op			token_type(char *str, int *i);

// var_expansion.c
char			*expand(char *str);
int				is_var_char(char c);

// cmd.c
t_cmd			*init_cmd(void);
t_cmd			*build_cmd(t_token	*token);
int				args_cmd(t_cmd *cmd, t_token *token);
int				in_cmd(t_cmd *cmd, t_token *token);
int				out_cmd(t_cmd *cmd, t_token *token);
t_cmd			*pipeline_cmd(t_token *token);

#endif
