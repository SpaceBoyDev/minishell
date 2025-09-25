/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:52:33 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/25 12:01:22 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "../signals/signals.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "../utils/utils.h"
#include "../builtins/builtins.h"

void	read_heredoc(pid_t pid, int *pipefd, char *delimeter, t_data *data)
{
	char	*line;

	if (pid == 0)
	{
		close(pipefd[0]);
		while (1)
		{
			line = readline("> ");
			if (!line || !ft_strcmp(line, delimeter))
			{
				free(line);
				break ;
			}
			write(pipefd[1], line, ft_strlen(line));
			write(pipefd[1], "\n", 1);
			free(line);
		}
		close(pipefd[1]);
		token_free(data->token);
		cmd_free(data->cmd);
		free_env(data);
		exit(EXIT_SUCCESS);
	}
}

// TODO: when running heredoc without cmd, after heredoc minishell
// struggles to exit with ^D and exit()
// TODO: make it work with a pipeline like: << a | << b
int	heredoc(char	*delimeter, t_data *data)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	signal(SIGINT, heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
	pipe(pipefd);
	pid = fork();
	read_heredoc(pid, pipefd, delimeter, data);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	close(pipefd[1]);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == HEREDOC_ERR)
	{
		write(1, "\n", 1);
		return (-1);
	}
	return (pipefd[0]);
}
