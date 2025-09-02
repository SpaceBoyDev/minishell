/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:28:27 by dario             #+#    #+#             */
/*   Updated: 2025/09/02 19:24:19 by marcos           ###   ########.fr       */
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

int	exec_builtins(t_cmd *cmd, char **env)
{
	if (ft_strcmp(cmd->cmd, "cd") == 0)
		return (ft_cd(cmd->args[1]));
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		return (ft_echo(cmd->args));
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		return (ft_env(env));
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		return (ft_export(cmd, env));
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		return (ft_pwd());
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
	{
		ft_exit();
		return (0);
	}
	return (1);
}
