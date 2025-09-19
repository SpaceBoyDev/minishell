/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:52:41 by dario             #+#    #+#             */
/*   Updated: 2025/09/19 11:31:22 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "../heredoc/heredoc.h"
#include "../builtins/builtins.h"

int	in_set(t_cmd *cmd)
{
	int	ret;

	if (cmd->infile && cmd->in_op == IN)
	{
		cmd->in_fd = open(cmd->infile, O_RDONLY);
		if (cmd->in_fd == -1)
		{
			perror(cmd->infile);
			return (0);
		}
		dup2(cmd->in_fd, 0);
		close(cmd->in_fd);
	}
	else if (cmd->infile && cmd->in_op == HEREDOC)
	{
		ret = heredoc_set(cmd);
		if (!ret)
			return (0);
	}
	return (1);
}

int heredoc_set(t_cmd *cmd)
{
	int	ofd;

	ofd = dup(1);
	dup2(cmd->in_std, 0);
	dup2(cmd->out_std, 1);
	cmd->in_fd = heredoc(cmd->infile);
	if (cmd->in_fd == -1)
		return (0);
	dup2(cmd->in_fd, 0);
	dup2(ofd, 1);
	close(ofd);
	close(cmd->in_fd);
	return (1);
}

int	out_set(t_cmd *cmd)
{
	if (cmd->outfile && cmd->out_op == OUT)
	{
		cmd->out_fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd->out_fd == -1)
		{
			perror(cmd->outfile);
			return (0);
		}
		dup2(cmd->out_fd, 1);
		close(cmd->out_fd);
	}
	else if (cmd->outfile && cmd->out_op == APPEND)
	{
		cmd->out_fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (cmd->out_fd == -1)
		{
			perror(cmd->outfile);
			return (0);
		}
		dup2(cmd->out_fd, 1);
		close(cmd->out_fd);
	}
	return (1);
}

int	io_set(t_cmd *cmd)
{
	if (!in_set(cmd))
		return (0);
	if (!out_set(cmd))
		return (0);
	return (1);
}
