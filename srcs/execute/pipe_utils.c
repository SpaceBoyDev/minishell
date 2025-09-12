/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:42:49 by dario             #+#    #+#             */
/*   Updated: 2025/09/12 19:53:48 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "../heredoc/heredoc.h"
#include "../builtins/builtins.h"

int	open_pipe(t_cmd *left, t_cmd *right)
{
	int	pipefd[2];

	if (right == NULL)
	{
		return (0);
	}
	pipe(pipefd);
	left->out_fd = pipefd[1];
	right->in_fd = pipefd[0];
	return (0);
}

int	io_pipes(t_cmd *cmd)
{
	cmd->in_std = dup(0);
	cmd->out_std = dup(1);
	if (cmd->in_fd != -1)
	{
		dup2(cmd->in_fd, 0);
		close(cmd->in_fd);
	}
	if (cmd->out_fd != -1)
	{
		dup2(cmd->out_fd, 1);
		close(cmd->out_fd);
	}
	return (0);
}

int	restore_io(t_cmd *cmd)
{
	if (cmd->in_fd != -1)
	{
		dup2(cmd->in_std, 0);
		close(cmd->in_std);
	}
	if (cmd->out_fd != -1)
	{
		dup2(cmd->out_std, 1);
		close(cmd->out_std);
	}
	return (0);
}

int	std_io(t_cmd *cmd)
{
	dup2(cmd->in_std, 0);
	close(cmd->in_std);
	dup2(cmd->out_std, 1);
	close(cmd->out_std);
	return (0);
}
