/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:17 by dario             #+#    #+#             */
/*   Updated: 2025/09/10 19:55:38 by marcolop         ###   ########.fr       */
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
	(void)free;
	free_env(data);
	token_free(data->token);
	rl_clear_history();
	cmd_free(data->cmd);
	if (free)
	{
	}
	exit(0);
}
