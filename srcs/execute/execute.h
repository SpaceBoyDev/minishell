/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:28:18 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/25 12:00:27 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../lexer/lexer.h"

# define CMD_NOT_FOUND 127

char	**get_paths(char **env);
void	ft_exec(t_data *data);

int		open_pipe(t_cmd *left, t_cmd *right);
int		pipeline(t_data *data);
void	update_shlvl(t_data *data, int op);

// pipe_utils.c
int		open_pipe(t_cmd *left, t_cmd *right);
int		io_pipes(t_cmd *cmd);
int		restore_io(t_cmd *cmd);
int		std_io(t_cmd *cmd);

// pipe_set.c
int		in_set(t_cmd *cmd, t_data *data);
int		out_set(t_cmd *cmd);
int		io_set(t_cmd *cmd, t_data *data);
int		heredoc_set(t_cmd *cmd, t_data *data);

#endif
