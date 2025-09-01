#include "execute.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	set_pipes(t_cmd *cmd)
{
	while (cmd->next != NULL)
	{
		pipe_connect(cmd, cmd->next);
		cmd = cmd->next;
	}
	return (0);
}

int pipe_connect(t_cmd *left, t_cmd *right)
{
	int	pipefd[2];

	pipe(pipefd);
	left->out_fd = pipefd[1];
	right->in_fd = pipefd[0];
	return (0);
}

int	close_pipe(t_cmd *left, t_cmd *right)
{
	if (right == NULL)
	{
		return (0);
	}
	close(left->out_fd);
	close(right->in_fd);
}

int	pipeline(t_cmd *cmd, char **env)
{
	(void)env;
	pid_t	pid;
	t_cmd	*first;

	first = cmd;
	while (cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			
			execute(cmd, env);
		}
		close_pipe(cmd, cmd->next);
		cmd = cmd->next;
	}
	while (first)
	{
		wait(NULL);
		first = first->next;
	}
	return (0);
}