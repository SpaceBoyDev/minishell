/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:17 by dario             #+#    #+#             */
/*   Updated: 2025/09/25 16:15:53 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	arg_len(t_data *data)
{
	int	ret;

	ret = 0;
	if (data && data->cmd->args)
		while (data->cmd->args[ret])
			ret++;
	return (ret);
}

static bool	is_numeric(const char *str)
{
	int	i;

	if (!str || !*str)
		return (false);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	ft_exit_more_args(t_data *data)
{
	if (!is_numeric(data->cmd->args[1]))
		return (2);
	else
	{
		printf("exit\nminishell: exit: too many arguments\n");
		return (1);
	}
}

void	free_data(t_data *data)
{
	free_env(data);
	token_free(data->token);
	rl_clear_history();
	cmd_free(data->cmd);
}

void	ft_exit(t_data *data)
{
	int	arg_count;
	int	exit_status;

	arg_count = arg_len(data);
	exit_status = 0;
	if (arg_count > 2)
	{
		exit_status = ft_exit_more_args(data);
		free_data(data);
		exit(exit_status);
	}
	if (arg_count == 2)
	{
		if (!is_numeric(data->cmd->args[1]))
			exit_status = 2;
		else
		{
			exit_status = ft_atoi(data->cmd->args[1]) % 256;
			if (exit_status < 0)
				exit_status += 256;
		}
	}
	free_data(data);
	exit(exit_status);
}
