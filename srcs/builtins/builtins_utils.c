/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:28:27 by dario             #+#    #+#             */
/*   Updated: 2025/07/13 02:53:09 by dario            ###   ########.fr       */
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

int	exec_builtins(char *path, char **args, char **env)
{
	if (!is_builtin(path))
		return (1);
	if (ft_strncmp(path, "cd", ft_strlen(path)) == 0)
		return (ft_cd(args[1]));
	else if (ft_strncmp(path, "echo", ft_strlen(path)) == 0)
		return (ft_echo(args[1]));
	else if (ft_strncmp(path, "pwd", ft_strlen(path)) == 0)
		return (ft_pwd());
	return (1);
}
