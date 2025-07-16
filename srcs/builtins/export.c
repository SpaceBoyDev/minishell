/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:19 by dario             #+#    #+#             */
/*   Updated: 2025/07/16 19:40:51 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_export(char **env)
{
	int		i;
	int		x;
	char	quotation;

	quotation = '"';
	i = 0;
	while (env[i])
	{
		x = 0;
		write(1, "declare -x ", 12);
		while (env[i][x])
		{
			write(1, &env[i][x], 1);
			if (env[i][x] == '=')
				write(1, "\"", 1);
			++x;
		}
		write(1, "\"\n", 2);
		++i;
	}
}

int	ft_export(t_cmd *cmd, char **env)
{
	if (!cmd->args[1])
		print_export(env);
	return (0);

}