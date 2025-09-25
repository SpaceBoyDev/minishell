/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:38:45 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/25 11:21:58 by marcos           ###   ########.fr       */
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
#include "../builtins/builtins.h"

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

void	ft_exec(t_data *data)
{
	char	**paths;
	int		i;
	char	*tmp;
	char	*str;

	if (!data->cmd->name)
		return ;
	execve(data->cmd->name, data->cmd->args, data->env);
	paths = get_paths(data->env);
	i = -1;
	while (paths && paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			break ;
		str = ft_strjoin(tmp, data->cmd->name);
		free(tmp);
		if (!str)
			break ;
		execve(str, data->cmd->args, data->env);
		free(str);
	}
	ft_putstr_fd(data->cmd->name, 2);
	ft_putstr_fd(": command not found\n", 2);
	table_free(paths);
	token_free(data->token);
	cmd_free(data->cmd);
	free_env(data);
	exit(CMD_NOT_FOUND);
}
