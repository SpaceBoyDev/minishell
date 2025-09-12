/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:23 by dario             #+#    #+#             */
/*   Updated: 2025/09/12 14:54:32 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../utils/utils.h"

int	ft_unset(t_data *data)
{
	int	i;
	int	j;

	if (!data->cmd->args[1])
		return (1);
	i = 0;
	j = 0;
	while (data->env[i])
	{
		if (ft_strcmp(data->env[i], data->cmd->args[1]) == 0
			&& data->env[i][ft_strlen(data->cmd->args[1])] == '=')
		{
			free(data->env[i]);
			i++;
			continue ;
		}
		data->env[j++] = data->env[i++];
	}
	data->env[j] = NULL;
	return (0);
}
