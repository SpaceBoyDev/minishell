/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:20 by dario             #+#    #+#             */
/*   Updated: 2025/07/16 19:23:43 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(void)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		printf("pwd: error retrieving current directory: getcwd: "
			"cannot access parent directories: No such file or directory\n");
		return (1);
	}
	printf("%s\n", getcwd(NULL, 0));
	return (0);
}
