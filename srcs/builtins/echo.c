/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:11 by dario             #+#    #+#             */
/*   Updated: 2025/09/10 18:37:37 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../utils/utils.h"
#include "../heredoc/heredoc.h"

int	ft_echo(char **args, t_data *data)
{
	int		i;
	bool	nl;

	(void)data;
	nl = (bool)ft_strcmp(args[1], "-n");
	if (nl)
		i = 1;
	else
		i = 2;
	while (args[i])
	{
		printf("%s", args[i]);
		++i;
		if (args[i])
			printf(" ");
	}
	if (nl)
		printf("\n");
	return (0);
}
