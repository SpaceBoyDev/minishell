/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:27:19 by dario             #+#    #+#             */
/*   Updated: 2025/07/26 21:42:52 by dario            ###   ########.fr       */
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
		printf(BLUE"REEMPLAZANDO\n"RST);
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

int	ft_export(t_cmd *cmd, char **env)
{
	char	**old_env;
	int		i;

	i = 1;
	if (!cmd->args[1])
		print_export(env);
	while (cmd->args[i])
	{
		old_env = env;
		env = set_env_var(cmd->args[i], old_env);
		++i;
	}
	return (0);
}

// int	main(int argc, char **argv, char **env)
// {
// 	char	**old_env;
// 	printf(YELLOW"___________________________________\n"RST);
// 	print_env(env);
// 	printf(YELLOW"___________________________________\n"RST);
// 	old_env = env;
// 	env = set_env_var("hola=1", old_env);
// 	printf(YELLOW"___________________________________\n"RST);
	
// 	print_env(env);
// 	printf(YELLOW"___________________________________\n"RST);
	
// 	old_env = env;
// 	env = set_env_var("hola=2", old_env);
// 	printf(YELLOW"___________________________________\n"RST);
	
// 	print_env(env);
// 	printf(YELLOW"___________________________________\n"RST);
// 		old_env = env;
// 	env = set_env_var("holaf=1", old_env);
// 	printf(YELLOW"___________________________________\n"RST);
	
// 	print_env(env);
// 	printf(YELLOW"___________________________________\n"RST);
// 		old_env = env;
// 	env = set_env_var("holaf=2", old_env);
// 	printf(YELLOW"___________________________________\n"RST);
	
// 	print_env(env);
// 	printf(YELLOW"___________________________________\n"RST);

// 	int env_len = 0;
// 	while (env[env_len])
// 		++env_len;
// 	printf("env len -> %i\n", env_len);

// 	old_env = env;
// 	env = unset_var(old_env, "hola", 85, 86);
// 	printf(YELLOW"___________________________________\n"RST);
	
// 	print_env(env);
// 	printf(YELLOW"___________________________________\n"RST);
	
// 	//replace_existing_var("hola=1", "hola=2");
// }