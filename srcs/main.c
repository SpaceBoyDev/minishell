/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 20:47:21 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "execute/execute.h"
#include "heredoc/heredoc.h"
#include "lexer/lexer.h"
#include "utils/utils.h"
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
	while (1)
	{
		setup_signal_handler();
		str = readline(PS1);
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
			free(str);
			ft_putstr_fd("quotation error\n", 2);
			continue ;
		}
		token = tokenize(str, last_status);
		if (!token)
		{
			free(str);
			ft_putstr_fd("tokenizing error\n", 2);
			continue ;
		}
		// print_tokens(token);
		// printf("--------------------------------\n");
		// cmd = build_cmd(token);
		cmd = pipeline_cmd(token);
		if (!cmd)
		{
			free(str);
			token_free(token);
			ft_putstr_fd("cmd build error\n", 2);
			continue ;
		}
		// print_cmd(cmd);
		// print_cmds(cmd);
		g_running_cmd = 1;
		last_status = create_processes(cmd, env);
		g_running_cmd = 0;
		free(str);
		token_free(token);
		cmd_free(cmd);
	}
	rl_clear_history();
	return (0);
}
