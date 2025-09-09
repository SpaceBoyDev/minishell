/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:19 by dario             #+#    #+#             */
/*   Updated: 2025/09/09 23:06:02 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_export(char **env)
{
	int		i;
	int		x;

	i = 0;
	while (env[i])
	{
		x = 0;
		write(1, "declare -x ", 12);
		while (env[i][x])
		{
			write(1, &env[i][x], 1);
			if (env[i][x] == '=')
				write(1, "\"", 1);
			++x;
		}
		write(1, "\"\n", 2);
		++i;
	}
}

void	print_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
}

static char	*replace_existing_var(char **env, char *new_var, int count)
{
	char	*old_var;

	old_var = env[count];
	if (ft_strncmp(old_var, new_var, ft_strchr(new_var, '=') - new_var) == 0
		&& old_var[ft_strchr(new_var, '=') - new_var] == '=')
	{
		free(env[count]);
		env[count] = ft_strdup(new_var);
		return (env[count]);
	}
	return (NULL);
}

static char	**set_env_var(char *new_var, char **old_env)
{
	char	**new_env;
	int		env_count;

	env_count = 0;
	if (!ft_strchr(new_var, '='))
		return (old_env);
	while (old_env[env_count])
	{
		if (replace_existing_var(old_env, new_var, env_count))
			return (old_env);
		++env_count;
	}
	new_env = malloc((env_count + 2) * sizeof(char *));
	if (!new_env)
		return (old_env);
	env_count = -1;
	while (old_env[++env_count])
		new_env[env_count] = ft_strdup(old_env[env_count]);
	new_env[env_count] = ft_strdup(new_var);
	new_env[env_count + 1] = NULL;
	return (new_env);
}

int	ft_export(t_data *data)
{
	char	**old_env;
	int		i;

	i = 1;
	if (!data->cmd->args[1])
		print_export(data->env);
	while (data->cmd->args[i])
	{
		old_env = data->env;
		data->env = set_env_var(data->cmd->args[i], old_env);
		++i;
	}
	return (0);
}
