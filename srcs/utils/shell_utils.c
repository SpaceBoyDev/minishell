/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:00:21 by dario             #+#    #+#             */
/*   Updated: 2025/09/25 11:35:40 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../signals/signals.h"

char	*prompt_rl(void)
{
	char	*cwd;
	char	*path;
	char	*prompt;

	cwd = getcwd(NULL, 0);
	path = ft_strjoin(PINK, cwd);
	prompt = ft_strjoin(path, "\033[5m> " RST);
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
	data->env[env_count] = NULL;
	update_shlvl(data, +1);
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
	free(needle);
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
