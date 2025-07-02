/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:28:18 by marcolop          #+#    #+#             */
/*   Updated: 2025/06/29 14:28:18 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../lexer/lexer.h"

char	**get_paths(void);
void	execute(t_cmd *cmd, char **env);
void	run_process(t_cmd *cmd, int *pipefd, char **env);
void	execute(t_cmd *cmd, char **env);
int		create_processes(t_cmd *cmd, char **env);

#endif
