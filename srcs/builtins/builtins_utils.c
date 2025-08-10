/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:28:27 by dario             #+#    #+#             */
/*   Updated: 2025/07/28 21:01:16 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "builtins.h"

static bool	is_builtin(const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (ft_strncmp(str, "echo", len) == 0
		|| ft_strncmp(str, "cd", len) == 0
		|| ft_strncmp(str, "pwd", len) == 0
		|| ft_strncmp(str, "export", len) == 0
		|| ft_strncmp(str, "unset", len) == 0
		|| ft_strncmp(str, "env", len) == 0
		|| ft_strncmp(str, "exit", len) == 0)
		return (true);
	return (false);
}

int	exec_builtins(t_cmd *cmd, char **env)
{
	if (!is_builtin(cmd->cmd))
		return (1);
	if (ft_strncmp(cmd->cmd, "cd", ft_strlen(cmd->cmd)) == 0)
		return (ft_cd(cmd->args[1]));
	else if (ft_strncmp(cmd->cmd, "echo", ft_strlen(cmd->cmd)) == 0)
		return (ft_echo(cmd->args));
	else if (ft_strncmp(cmd->cmd, "env", ft_strlen(cmd->cmd)) == 0)
		return (ft_env(env));
	else if (ft_strncmp(cmd->cmd, "export", ft_strlen(cmd->cmd)) == 0)
		return (ft_export(cmd, env));
	else if (ft_strncmp(cmd->cmd, "pwd", ft_strlen(cmd->cmd)) == 0)
		return (ft_pwd());
	else if (ft_strncmp(cmd->cmd, "exit", ft_strlen(cmd->cmd)) == 0)
	{
		ft_exit();
		return (0);
	}
	return (1);
}
