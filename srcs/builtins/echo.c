/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:11 by dario             #+#    #+#             */
/*   Updated: 2025/09/09 16:42:40 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../utils/utils.h"
#include "../heredoc/heredoc.h"

void	print_env_var(char *var, t_data *data)
{
	char	*env_var;

	env_var = expand(var, data);
	printf("%s", env_var);
	free(env_var);
}

int	ft_echo(char **args, t_data *data)
{
	int		i;
	bool	nl;

	nl = (bool)ft_strcmp(args[1], "-n");
	if (nl)
		i = 1;
	else
		i = 2;
	while (args[i])
	{
		if (args[i][0] == '$')
			print_env_var(args[i], data);
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
