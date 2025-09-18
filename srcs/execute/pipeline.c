/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:00:09 by marcos            #+#    #+#             */
/*   Updated: 2025/09/18 11:22:42 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../builtins/builtins.h"
#include "../heredoc/heredoc.h"

int	manage_pipe(t_data *data)
{
	pid_t	pid;

	open_pipe(data->cmd, data->cmd->next);
	io_pipes(data->cmd);
	if (!io_set(data->cmd))
	{
		std_io(data->cmd);
		data->cmd = data->cmd->next;
		return (1);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (is_builtin(data->cmd->name))
		data->cmd->ret = exec_builtins(data);
	else
	{
		pid = fork();
		if (pid == 0)
			ft_exec(data->cmd, data->env);
		data->cmd->pid = pid;
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	restore_io(data->cmd);
	data->cmd = data->cmd->next;
	return (0);
}

int	pipeline(t_data *data)
{
	t_cmd	*cmd_cpy;
	int		status;

	cmd_cpy = data->cmd;
	while (data->cmd)
		if (manage_pipe(data) == 1)
			return (1);
	while (cmd_cpy)
	{
		if (!is_builtin(cmd_cpy->name))
		{
			waitpid(cmd_cpy->pid, &status, 0);
			status = WEXITSTATUS(status);
		}
		else
			status = cmd_cpy->ret;
		cmd_cpy = cmd_cpy->next;
	}
	return (status);
}
