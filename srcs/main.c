/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/08/10 16:30:11 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "heredoc/heredoc.h"
#include "utils/utils.h"
#include "builtins/builtins.h"
#include "minishell.h"
#include "tester/test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PS1 "minishell> "

volatile sig_atomic_t g_running_cmd = 0;

int	main(int argc, char **argv, char **env)
{
	char	*str;
	t_token	*token;
	t_cmd	*cmd;
	int		last_status;

	(void)argc;
	(void)argv;
	(void)env;
	// run_tests();
	// return (0);
	last_status = 0;

	if (argc != 1)
	{
		token = NULL;
		cmd = NULL;
		return (run_non_interactive(argv[1], token, cmd, env));
	}
	while (1)
	{
		setup_signal_handler();
		str = readline(prompt_rl());
		if (!str)
		{
			printf("Leaving minishell...\n");
			break ;
		}
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
		token = tokenize(str, last_status);
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
		g_running_cmd = 1;
		last_status = create_processes(cmd, env);
		g_running_cmd = 0;
	}

	return (0);
}
