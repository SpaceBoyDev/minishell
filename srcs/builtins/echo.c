/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:11 by dario             #+#    #+#             */
/*   Updated: 2025/09/08 12:58:54 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../utils/utils.h"

char	*create_env_var(char *var)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(var)));
	i = 0;
	while (var[++i])
		str[i - 1] = var[i];
	str[i] = '\0';
	return (str);
}

int	ft_echo(char **args, char **env)
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
		if (args[i][0] == '$')
		{
			printf("%s", ft_getenv(create_env_var(args[i]), env));
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
