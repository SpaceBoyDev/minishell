/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:19 by dario             #+#    #+#             */
/*   Updated: 2025/09/19 20:41:21 by dario            ###   ########.fr       */
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

int		table_len(char **table)
{
	int	len;

	len = 0;
	while (table[len])
		++len;
	return (len);
}

static char	*replace_existing_var(char **env, char **args,
				int count, t_vars *vars)
{
	char	*old_var;
	int		i;

	i = vars->i;
	old_var = env[count];
	if (ft_strncmp(old_var, args[i], ft_strchr(args[i], '=') - args[i]) == 0
		&& old_var[ft_strchr(args[i], '=') - args[i]] == '=')
	{
		free(env[count]);
		if (vars->next_var)
			env[count] = ft_strdup(ft_strjoin(args[i], args[i + 1]));
		else
			env[count] = ft_strdup(args[i]);
		return (env[count]);
	}
	return (NULL);
}

static char	**set_env_var(char **args, char **old_env, int i)
{
	char	**new_env;
	int		env_count;
	t_vars	aux;

	aux.i = i;
	env_count = -1;
	if (!ft_strchr(args[i], '='))
		return (old_env);
	aux.next_var = (args[i][ft_strchr(args[i], '=') - args[i] + 1] == '\0'
			&& args[i + 1] && !ft_strchr(args[i + 1], '='));
	while (old_env[++env_count])
		if (replace_existing_var(old_env, args, env_count, &aux))
			return (old_env);
	new_env = malloc((env_count + 2) * sizeof(char *));
	if (!new_env)
		return (old_env);
	env_count = -1;
	while (old_env[++env_count])
		new_env[env_count] = ft_strdup(old_env[env_count]);
	if (aux.next_var)
		new_env[env_count] = ft_strdup(ft_strjoin(args[i], args[i + 1]));
	else
		new_env[env_count] = ft_strdup(args[i]);
	new_env[env_count + 1] = NULL;
	return (new_env);
}

int	ft_export(t_data *data)
{
	char	**old_env;
	int		i;
	int		old_len;

	i = 1;
	if (!data->cmd->args[1])
		print_export(data->env);
	while (data->cmd->args[i])
	{
		old_env = data->env;
		old_len = table_len(old_env);
		data->env = set_env_var(data->cmd->args, old_env, i);
		if (old_len != table_len(data->env))
			table_free(old_env);
		++i;
	}
	return (0);
}
