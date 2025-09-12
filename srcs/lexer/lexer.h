/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:46:48 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/12 19:37:26 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <sys/types.h>

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
	char			*name;
	char			**args;
	char			*infile;
	char			*outfile;
	t_op			in_op;
	t_op			out_op;
	int				in_fd;
	int				out_fd;
	int				in_std;
	int				out_std;
	pid_t			pid;
	int				ret;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_token	*token;
	t_cmd	*cmd;
	char	**env;
	int		last_status;
}	t_data;

typedef struct s_build_tkn
{
	char	*val;
	int		start;
	char	*tmp;
	char	tmp_char;
}	t_build_tkn;

// utils.c
int				check_quotes(char *str);
void			print_token(t_token *token);
void			print_tokens(t_token *token);
void			print_cmd(t_cmd	*cmd);
void			print_cmds(t_cmd	*cmd);

// token.c
t_token			*tokenize(char *input, t_data *data);
t_token			*create_token(char *str, int *i, t_data *data);
t_op			token_type(char *str, int *i);
void			token_free(t_token *token);

// var_expansion.c
char			*expand(char *str, t_data *data);
char			*get_var_name(char *str);
char			*get_env_val(char *var_name, t_data *data);
int				skip_var_name(char *str, int i);

// cmd.c
t_cmd			*init_cmd(void);
t_cmd			*build_cmd(t_token	*token);
t_cmd			*pipeline_cmd(t_token *token);
int				args_cmd(t_cmd *cmd, t_token *token);

// cmd_utils.c
int				len_until_char(char *str, int i, char character);
int				in_cmd(t_cmd *cmd, t_token *token);
int				out_cmd(t_cmd *cmd, t_token *token);
void			cmd_free(t_cmd *cmd);
void			table_free(char **table);

// token_str.c
char			*token_str(char *str, int *i, t_data *data);
char			*build_val(char *str, int *i, t_data *data);

// nbr_to_str.c
char			*nbr_to_str(int n);

#endif
