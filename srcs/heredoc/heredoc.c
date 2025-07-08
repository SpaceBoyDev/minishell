/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:52:33 by marcolop          #+#    #+#             */
/*   Updated: 2025/07/02 13:52:33 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include <limits.h>
#include <stddef.h>

char *heredoc_rl(char *delimeter)

// char	*heredoc_rl(char *delimeter)
// {
// 	char	*line;
// 	char	*input;
// 	char	*tmp;
//
// 	line = NULL;
// 	input = NULL;
// 	while (1)
// 	{
// 		if (line)
// 			free(line);
// 		tmp = readline("> ");
// 		if (!ft_strcmp(tmp, delimeter))
// 		{
// 			free(tmp);
// 			return (input);
// 		}
// 		line = ft_strjoin(tmp, "\n");
// 		free(tmp);
// 		tmp = input;
// 		input = ft_strjoin(tmp, line);
// 		if (tmp)
// 			free(tmp);
// 	}
// 	return (input);
// }

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
