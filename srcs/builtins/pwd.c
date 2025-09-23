/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:20 by dario             #+#    #+#             */
/*   Updated: 2025/09/23 16:43:54 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(void)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (!current_dir)
	{
		return (1);
	}
	printf("%s\n", current_dir);
	free(current_dir);
	return (0);
}
