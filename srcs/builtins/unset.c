/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:23 by dario             #+#    #+#             */
/*   Updated: 2025/07/26 21:42:38 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	**unset_var(char *vardlt, int count, char **env, int env_len)
{
	char	**new_env;
	char	*old_var;
	int		i;

	old_var = env[count];
	if (ft_strncmp(old_var, vardlt, ft_strchr(vardlt, '=') - vardlt) == 0
		&& old_var[ft_strchr(vardlt, '=') - vardlt] == '=')
	{
		new_env = malloc((env_len) * sizeof(char *));
		if (!new_env)
			return (env);
		i = -1;
		while (env[++i])
		{
			if (i != count)
				new_env[i] = ft_strdup(env[i]);
		}
		new_env[i + 1] = NULL;
		return (new_env);
	}
	return (env);
}

int	ft_unset(t_cmd *cmd, char **env)
{
	char	**old_env;
	int		i;
	int		env_len;

	i = 1;
	env_len = 0;
	while (env[env_len])
		++env_len;
	while (cmd->args[i])
	{
		old_env = env;
		env = unset_var(old_env, cmd->args[i], i, env_len);
		++i;
	}
	return (0);
}
