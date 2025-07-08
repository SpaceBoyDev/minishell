/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:52:30 by marcolop          #+#    #+#             */
/*   Updated: 2025/07/02 13:52:30 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "../minishell.h"

void	heredoc(char	*delimeter);
char	*heredoc_rl(char *delimeter);
int		ft_strcmp(char *s1, char *s2);

#endif
