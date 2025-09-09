/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:00:21 by dario             #+#    #+#             */
/*   Updated: 2025/09/10 01:51:10 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../signals/signals.h"

char	*create_path(char *home, char *display)
{
	char	*path;

	path = ft_strjoin(BLUE, home);
	path = ft_strjoin(path, RST);
	if (home)
		path = ft_strjoin(path, ":");
	path = ft_strjoin(path, PINK);
	path = ft_strjoin(path, display);
	return (path);
}

char	*prompt_rl(t_data *data)
{
	char	*cwd;
	char	*home;
	char	*display;
	char	*path;
	char	*prompt;

	cwd = getcwd(NULL, 0);
	home = ft_getenv("HOME", data->env);
	if (home && ft_strncmp(cwd, home, ft_strlen(home)) == 0)
	{
		display = cwd + ft_strlen(home);
		display = ft_strjoin("~", display);
	}
	else
		display = ft_strjoin(cwd, NULL);
	home = ft_getenv("LOGNAME", data->env);
	path = create_path(home, display);
	prompt = ft_strjoin(path, "\033[5m> " RST);
	free(display);
	free(path);
	free(cwd);
	return (prompt);
}

void	init_data_env(char **src, t_data *data)
{
	int	env_count;

	env_count = 0;
	while (src[env_count])
		++env_count;
	data->env = malloc((env_count + 1) * sizeof(char *));
	if (!data->env)
		return ;
	env_count = -1;
	while (src[++env_count])
		data->env[env_count] = ft_strdup(src[env_count]);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	char	*needle;

	needle = ft_strjoin(name, "=");
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(needle, env[i], ft_strlen(needle)))
		{
			free(needle);
			return (&env[i][ft_strlen(name) + 1]);
		}
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
