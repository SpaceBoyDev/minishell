/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:11 by dario             #+#    #+#             */
/*   Updated: 2025/09/08 13:31:51 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../utils/utils.h"
#include "../heredoc/heredoc.h"

void	print_env_var(char *var)
{
	char	*env_var;

	env_var = expand(var, 0);
	printf("%s", env_var);
	free(env_var);
}

int	ft_echo(char **args, char **env)
{
	int		i;
	bool	nl;

	(void)env;
	nl = (bool)ft_strcmp(args[1], "-n");
	if (nl)
		i = 1;
	else
		i = 2;
	while (args[i])
	{
		if (args[i][0] == '$')
			print_env_var(args[i]);
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
