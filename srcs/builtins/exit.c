/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:17 by dario             #+#    #+#             */
/*   Updated: 2025/09/10 13:03:56 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	free_env(t_data *data)
{
	if (data && data->env)
	{
		char **env = data->env;
		int i = 0;
		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env);
		data->env = NULL;
	}
}

void	ft_exit(t_data *data)
{
	free_env(data);
	exit(0);
}
