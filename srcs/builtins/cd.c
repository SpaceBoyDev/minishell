/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:08 by dario             #+#    #+#             */
/*   Updated: 2025/09/12 13:52:14 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../utils/utils.h"

int	ft_cd(char *path, char **env)
{
	char	*home;

	if (!path)
	{
		home = ft_getenv("HOME", env);
		if (!home)
		{
			ft_putstr_fd("HOME not found\n", 2);
			return (1);
		}
		if (chdir(home) != 0)
		{
			ft_putstr_fd("Could not change directory to HOME", 2);
			return (1);
		}
		return (0);
	}
	if (chdir(path) != 0)
	{
		perror(path);
		return (1);
	}
	return (0);
}
