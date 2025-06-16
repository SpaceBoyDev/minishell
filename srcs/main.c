/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/06/16 18:47:06 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt_rl(void)
{
	char	*cwd;
	char	*path;
	char	*prompt;

	cwd = getcwd(NULL, 0);
	path = ft_strjoin(PINK, cwd);
	prompt = ft_strjoin(path, "$ " RST);
	free(path);
	free(cwd);
	return (prompt);
}

int	main(void)
{
	char	*rl;

	if (!isatty(STDIN_FILENO))
		return (0);
    rl = readline(prompt_rl());
	//echo(rl);
	cd(rl);
    rl = readline(prompt_rl());
	pwd();
	free(rl);
	return (0);
}
