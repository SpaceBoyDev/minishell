/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:38:45 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/12 14:33:19 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "execute.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>
#include "../heredoc/heredoc.h"
#include "../utils/utils.h"

char	**get_paths(char **env)
{
	char	*path_str;
	char	**paths;

	path_str = ft_getenv("PATH", env);
	if (!path_str)
		return (NULL);
	paths = ft_split(path_str, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

void	ft_exec(t_cmd *cmd, char **env)
{
	char	**paths;
	int		i;
	char	*tmp;
	char	*str;

	execve(cmd->name, cmd->args, env);
	paths = get_paths(env);
	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return ;
		str = ft_strjoin(tmp, cmd->name);
		free(tmp);
		if (!str)
			return ;
		execve(str, cmd->args, env);
		free(str);
		i++;
	}
	ft_putstr_fd(cmd->name, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(CMD_NOT_FOUND);
}
