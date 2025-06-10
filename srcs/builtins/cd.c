/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:08 by dario             #+#    #+#             */
/*   Updated: 2025/06/10 22:00:38 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd(char *path)
{
	char *home;

	if (!path)
	{
		home = getenv("HOME");
		if (!home)
		{
			printf("minishell: cd: HOME not set\n");
			return (1);
		}
		if (chdir(home) != 0)
		{
			printf("minishell: cd: HOME: No such file or directory");
			return (1);
		}
		return (0);
	}
	if (chdir(path) != 0)
	{
		printf("minishell: cd: %s: No such file or directory\n", path);
		return (1);
	}
	return (0);
}
