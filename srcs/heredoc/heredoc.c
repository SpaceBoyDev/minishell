/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:52:33 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/19 12:19:38 by marcolop         ###   ########.fr       */
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

void	read_heredoc(pid_t pid, int *pipefd, char *delimeter)
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
		exit(EXIT_SUCCESS);
	}
}

// TODO: when running heredoc without cmd, after heredoc minishell
// struggles to exit with ^D and exit()
int	heredoc(char	*delimeter)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	signal(SIGINT, heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
	pipe(pipefd);
	pid = fork();
	read_heredoc(pid, pipefd, delimeter);
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
