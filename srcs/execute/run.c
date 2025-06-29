/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:38:45 by marcolop          #+#    #+#             */
/*   Updated: 2025/06/29 14:38:45 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "execute.h"
#include <sys/types.h>
#include <unistd.h>

char	**get_paths(void)
{
	char	*path_str;
	char	**paths;

	path_str = getenv("PATH");
	if (!path_str)
		return (NULL); // TODO: error message?
	paths = ft_split(path_str, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

void	execute(t_cmd *cmd, char **env)
{
	char	**paths;
	int		i;
	char	*tmp;
	char	*str;

	paths = get_paths();
	if (!paths)
		return ;
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return ;
		str = ft_strjoin(tmp, cmd->cmd);
		free(tmp);
		if (!str)
			return ;
		execve(str, cmd->args, env);
		free(str);
		i++;
	}
}

// TODO: I was working here
// create pipes from first till last - 1
// fork for every cmd
// redirect input and output
void	create_processes(t_cmd *cmd)
{
}
