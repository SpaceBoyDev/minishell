#include "execute.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../builtins/builtins.h"
#include "../heredoc/heredoc.h"

int open_pipe(t_cmd *left, t_cmd *right)
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

int	io_set(t_cmd *cmd)
{
	if (cmd-> infile && cmd->in_op == IN)
	{
		cmd->in_fd = open(cmd->infile, O_RDONLY);
		dup2(cmd->in_fd, 0);
		close(cmd->in_fd);
	}
	else if (cmd->infile && cmd->in_op == HEREDOC)
	{
		cmd->in_fd = heredoc(cmd->infile);
		dup2(cmd->in_fd, 0);
		close(cmd->in_fd);
	}
	if (cmd->outfile && cmd->out_op == OUT)
	{
		cmd->out_fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(cmd->out_fd, 1);
		close(cmd->out_fd);
	}
	else if (cmd->outfile && cmd->out_op == APPEND)
	{
		cmd->out_fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(cmd->out_fd, 1);
		close(cmd->out_fd);
	}
	return (0);
}

int	pipeline(t_cmd *cmd, char **env)
{
	pid_t	pid;
	t_cmd	*first;

	first = cmd;
	while (cmd)
	{
		open_pipe(cmd, cmd->next);
		io_pipes(cmd);
		io_set(cmd);
		if (is_builtin(cmd->cmd))
		{
			exec_builtins(cmd, env);
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				ft_exec(cmd, env);
			}
		}
		restore_io(cmd);
		cmd = cmd->next;
	}
	while (first)
	{
		wait(NULL);
		first = first->next;
	}
	return (0);
}