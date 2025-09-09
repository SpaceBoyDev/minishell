/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:28:27 by dario             #+#    #+#             */
/*   Updated: 2025/09/09 16:41:41 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "builtins.h"
#include "../heredoc/heredoc.h"

int	is_builtin(char *str)
{
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
		return (ft_cd(data->cmd->args[1]));
	else if (ft_strcmp(data->cmd->name, "echo") == 0)
		return (ft_echo(data->cmd->args, data));
	else if (ft_strcmp(data->cmd->name, "env") == 0)
		return (ft_env(data->env));
	else if (ft_strcmp(data->cmd->name, "export") == 0)
		return (ft_export(data->cmd, data->env));
	else if (ft_strcmp(data->cmd->name, "pwd") == 0)
		return (ft_pwd());
	else if (ft_strcmp(data->cmd->name, "exit") == 0)
	{
		ft_exit();
		return (0);
	}
	return (1);
}
