/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/06/25 21:22:33 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/history.h>

#define PS1 "minishell> "

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

int	main(void)
{
	char	*str;
	t_token	*token;

	while (1)
	{
		str = readline(prompt_rl());
		add_history(str);
		if (!check_quotes(str))
		{
			ft_putstr_fd("syntax error (quotes)\n", 2);
			continue ;
		}
		token = tokenize(str);
		if (!token)
			ft_putstr_fd("syntax error\n", 2);
		else
		{
			exec_builtins(token);
		}
		print_tokens(token);
	}

	return (0);
}
