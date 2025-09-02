/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:52:33 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/02 20:13:30 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int	heredoc(char	*delimeter)
{
	pid_t	pid;
	char	*input;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		input = heredoc_rl(delimeter); // TODO: check return?
		write(pipefd[1], input, ft_strlen(input));
		free(input);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);
	// dup2(pipefd[0], 0);
	// close(pipefd[0]);
	waitpid(pid, NULL, 0);
	return (pipefd[0]);
}

char	*heredoc_rl(char *delimeter)
{
	char	*line;
	char	*input;
	char	*tmp;

	line = NULL;
	input = NULL;
	while (1)
	{
		if (line)
			free(line);
		tmp = readline("> ");
		if (!ft_strcmp(tmp, delimeter))
		{
			free(tmp);
			return (input);
		}
		line = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp = input;
		input = ft_strjoin(tmp, line);
		if (tmp)
			free(tmp);
	}
	return (input);
}

int		ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
