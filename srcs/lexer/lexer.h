/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:46:48 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/01 15:21:26 by dario            ###   ########.fr       */
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
void			print_cmd(t_cmd	*cmd);
void			print_cmds(t_cmd	*cmd);

// token.c
t_token			*tokenize(char *input, int last_status);
t_token			*create_token(char *str, int *i, int last_status);
t_op			token_type(char *str, int *i);
void			token_free(t_token *token);

// var_expansion.c
char			*expand(char *str, int last_status);
char			*get_var_name(char *str);
char			*get_env_val(char *var_name);
int				skip_var_name(char  *str, int i);

// cmd.c
t_cmd			*init_cmd(void);
t_cmd			*build_cmd(t_token	*token);
t_cmd			*pipeline_cmd(t_token *token);
int				args_cmd(t_cmd *cmd, t_token *token);

// cmd_utils.c
int				in_cmd(t_cmd *cmd, t_token *token);
int				out_cmd(t_cmd *cmd, t_token *token);
void			cmd_free(t_cmd *cmd);
void			table_free(char **table);

// token_str.c
char			*token_str(char *str, int *i, int last_status);


// nbr_to_str.c
char			*nbr_to_str(int n);

#endif
