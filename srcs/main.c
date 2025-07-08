/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 01:17:11 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute/execute.h"
#include "heredoc/heredoc.h"
#include "lexer/lexer.h"
#include "utils/utils.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

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

int	main(int argc, char **argv, char **env)
{
	char	*str;
	t_token	*token;
	t_cmd	*cmd;

	(void)argc;
	(void)argv;
	(void)env;
	while (1)
	{
		start_minishell();
		str = readline(prompt_rl());
		if (!str)
			exit(EXIT_SUCCESS);
		else if (!str[0])
		{
			continue;
		}
		add_history(str);
		if (!check_quotes(str))
		{
			ft_putstr_fd("quotation error\n", 2);
			continue ;
		}
		token = tokenize(str);
		if (!token)
		{
			ft_putstr_fd("tokenizing error\n", 2);
			continue ;
		}
		// print_tokens(token);
		// printf("--------------------------------\n");
		// cmd = build_cmd(token);
		cmd = pipeline_cmd(token);
		if (!cmd)
		{
			ft_putstr_fd("cmd build error\n", 2);
			continue ;
		}
		// print_cmd(cmd);
		// print_cmds(cmd);
		create_processes(cmd, env);
	}

	return (0);
}
