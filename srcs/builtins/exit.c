/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:17 by dario             #+#    #+#             */
/*   Updated: 2025/09/10 18:00:42 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	free_env(t_data *data)
{
	char	**env;
	int		i;

	if (data && data->env)
	{
		env = data->env;
		i = 0;
		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env);
		data->env = NULL;
	}
}

void	ft_exit(t_data *data, bool free)
{
	free_env(data);
	rl_clear_history();
	if (free)
	{
		token_free(data->token);
		cmd_free(data->cmd);
	}
	exit(0);
}
