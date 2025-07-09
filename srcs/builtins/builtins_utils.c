/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:28:27 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 20:48:12 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd(char *path);
int	echo(char *str);
int	pwd(void);

static bool	is_builtin(char *str)
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

int	exec_builtins(t_token *token)
{
	char	*next_str;

	if (!is_builtin(token->str))
		return (1);
	if (!token->next || !token->next->str)
		next_str = NULL;
	else
		next_str = token->next->str;
	if (ft_strncmp(token->str, "cd", ft_strlen(token->str)) == 0)
		return (cd(next_str));
	else if (ft_strncmp(token->str, "echo", ft_strlen(token->str)) == 0)
		return (echo(next_str));
	else if (ft_strncmp(token->str, "pwd", ft_strlen(token->str)) == 0)
		return (pwd());
	return (1);
}
