/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:54:02 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 20:45:23 by dario            ###   ########.fr       */
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

void	start_minishell(void)
{
	struct sigaction	sa;

	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &sigint_handler_default;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		error_msg("Sigaction failed", true);
}
