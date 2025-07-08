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
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>
#include "../heredoc/heredoc.h"

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
	exit(EXIT_FAILURE);
}

int	create_processes(t_cmd *cmd, char **env)
{
	int		pipefd[4];
	pid_t	pid;
	t_cmd	*first;
	int		status;

	pipefd[0] = INT_MAX;
	pipefd[1] = INT_MAX;
	pipefd[2] = INT_MAX;
	pipefd[3] = INT_MAX;
	first = cmd;
	while (cmd)
	{
		if (cmd->next)
			pipe(&pipefd[2]); // TODO: check return?
		else
		{
			pipefd[2] = INT_MAX;
			pipefd[3] = INT_MAX;
		}
		pid = fork(); // TODO: check return?
		if (pid == 0)
			run_process(cmd, pipefd, env);
		cmd->pid = pid;
		cmd = cmd->next;
		if (pipefd[0] != INT_MAX)
			close(pipefd[0]);
		if (pipefd[1] != INT_MAX)
			close(pipefd[1]);
		pipefd[0] = pipefd[2];
		pipefd[1] = pipefd[3];
	}
	while (first)
	{
		// wait(NULL);
		waitpid(first->pid, &status, 0);
		first = first->next;
	}
	return (WEXITSTATUS(status));
}


// TODO: heredoc and append
void	run_process(t_cmd *cmd, int *pipefd, char **env)
{
	if (pipefd[1] != INT_MAX)
		close(pipefd[1]);
	if (pipefd[2] != INT_MAX)
		close(pipefd[2]);


	if (cmd->infile && cmd->in_op == IN)
	{
		close(pipefd[0]);
		cmd->in_fd = open(cmd->infile, O_RDONLY);
		dup2(cmd->in_fd, 0);
		close(cmd->in_fd);
	}
	else if (cmd->infile && cmd->in_op == HEREDOC)
	{
		close(pipefd[0]);
		heredoc(cmd->infile);
	}
	if (cmd->outfile && cmd->out_op == OUT)
	{
		close(pipefd[3]);
		cmd->out_fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(cmd->out_fd, 1);
		close(cmd->out_fd);
	}
	execute(cmd, env);
}
