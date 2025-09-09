/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:08 by dario             #+#    #+#             */
/*   Updated: 2025/09/09 21:34:09 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_cd(char *path)
{
	if (!path)
	{
		return (0);
	}
	if (chdir(path) != 0)
	{
		printf("minishell: cd: %s: No such file or directory\n", path);
		return (1);
	}
	return (0);
}
