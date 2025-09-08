/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:11 by dario             #+#    #+#             */
/*   Updated: 2025/09/08 13:14:58 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../utils/utils.h"
#include "../heredoc/heredoc.h"

int	ft_echo(char **args, char **env)
{
	int		i;
	bool	nl;
	char	*env_var;

	(void)env;
	nl = (bool)ft_strcmp(args[1], "-n");
	if (nl)
		i = 1;
	else
		i = 2;
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			env_var = expand(args[i], 0);
			printf("%s", env_var);
			free(env_var);
		}
		else
			printf("%s", args[i]);
		++i;
		if (args[i])
			printf(" ");
	}
	if (nl)
		printf("\n");
	return (0);
}
