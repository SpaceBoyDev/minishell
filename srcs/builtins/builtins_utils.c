/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:28:27 by dario             #+#    #+#             */
/*   Updated: 2025/09/26 03:43:26 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "builtins.h"
#include "../utils/utils.h"

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
		ft_exit(data);
		return (0);
	}
	return (1);
}

void	create_new_env(t_vars *aux, char **args, char **new_env, int i)
{
	char	*tmp;

	if (aux->next_var)
	{
		tmp = ft_strjoin(args[i], args[i + 1]);
		new_env[aux->env_count] = ft_strdup(tmp);
		free(tmp);
	}
	else
		new_env[aux->env_count] = ft_strdup(args[i]);
}
