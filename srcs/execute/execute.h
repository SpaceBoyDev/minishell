/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:28:18 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/01 13:43:54 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../lexer/lexer.h"

# define CMD_NOT_FOUND 127

char	**get_paths(void);
void	execute(t_cmd *cmd, char **env);
void	run_process(t_cmd *cmd, int *pipefd, char **env);
void	execute(t_cmd *cmd, char **env);
int		create_processes(t_cmd *cmd, char **env);


int	set_pipes(t_cmd *cmd);
int pipe_connect(t_cmd *left, t_cmd *right);
int	pipeline(t_cmd *cmd, char **env);

#endif
