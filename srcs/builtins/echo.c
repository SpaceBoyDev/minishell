/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:11 by dario             #+#    #+#             */
/*   Updated: 2025/09/01 13:04:52 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_echo(char **args) //TODO: fix printing when multiple args
{
	int		i;
	bool	nl;

	nl = (bool)ft_strncmp(args[1], "-n", ft_strlen(args[1]));
	if (nl)
		i = 1;
	else
		i = 2;
	while (args[i])
	{
		printf("%s", args[i]);
		++i;
	}
	if (nl)
		printf("\n");
	return (0);
}
