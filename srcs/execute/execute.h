/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:28:18 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/19 11:40:50 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../lexer/lexer.h"

# define CMD_NOT_FOUND 127

char	**get_paths(char **env);
void	ft_exec(t_cmd *cmd, char **env);

int		open_pipe(t_cmd *left, t_cmd *right);
int		pipeline(t_data *data);
void	update_shlvl(t_data *data, int op);

// pipe_utils.c
int		open_pipe(t_cmd *left, t_cmd *right);
int		io_pipes(t_cmd *cmd);
int		restore_io(t_cmd *cmd);
int		std_io(t_cmd *cmd);

// pipe_set.c
int		in_set(t_cmd *cmd);
int		out_set(t_cmd *cmd);
int		io_set(t_cmd *cmd);
int		heredoc_set(t_cmd *cmd);

#endif
