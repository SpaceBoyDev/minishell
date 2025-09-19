/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:28:27 by dario             #+#    #+#             */
/*   Updated: 2025/09/19 12:03:14 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "builtins.h"
#include "../utils/utils.h"

int	is_builtin(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "echo") == 0
		|| ft_strcmp(str, "cd") == 0
		|| ft_strcmp(str, "pwd") == 0
		|| ft_strcmp(str, "export") == 0
		|| ft_strcmp(str, "unset") == 0
		|| ft_strcmp(str, "env") == 0
		|| ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

int	exec_builtins(t_data *data)
{
	if (ft_strcmp(data->cmd->name, "cd") == 0)
		return (ft_cd(data->cmd->args[1], data->env));
	else if (ft_strcmp(data->cmd->name, "echo") == 0)
		return (ft_echo(data->cmd->args, data));
	else if (ft_strcmp(data->cmd->name, "env") == 0)
		return (ft_env(data->env));
	else if (ft_strcmp(data->cmd->name, "export") == 0)
		return (ft_export(data));
	else if (ft_strcmp(data->cmd->name, "pwd") == 0)
		return (ft_pwd());
	else if (ft_strcmp(data->cmd->name, "unset") == 0)
		return (ft_unset(data));
	else if (ft_strcmp(data->cmd->name, "exit") == 0)
	{
		ft_exit(data, false);
		return (0);
	}
	return (1);
}
