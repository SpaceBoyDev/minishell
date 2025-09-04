/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:00:21 by dario             #+#    #+#             */
/*   Updated: 2025/09/04 02:08:16 by dario            ###   ########.fr       */
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
}
