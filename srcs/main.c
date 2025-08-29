/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/08/29 13:38:11 by darmarti         ###   ########.fr       */
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

volatile sig_atomic_t g_running_cmd = 0;

void	run_interactive(char *str, t_data *data)
{
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
		data->token = tokenize(str, data->last_status);
		if (!data->token)
		{
			free(str);
			ft_putstr_fd("tokenizing error\n", 2);
			continue ;
		}
		data->cmd = pipeline_cmd(data->token);
		if (!data->cmd)
		{
			free(str);
			token_free(data->token);
			ft_putstr_fd("cmd build error\n", 2);
			continue ;
		}
		g_running_cmd = 1;
		data->last_status = create_processes(data->cmd, data->env);
		g_running_cmd = 0;
		free(str);
		token_free(data->token);
		cmd_free(data->cmd);
	}
}

void	copy_env(char **src, char **dst)
{
	int	env_count;

	env_count = 0;
	while (src[env_count])
		++env_count;
	dst = malloc((env_count + 1) * sizeof(char *));
	if (!dst)
		return ;
	env_count = -1;
	while (src[++env_count])
		dst[env_count] = ft_strdup(src[env_count]);
}

int	main(int argc, char **argv, char **env)
{
	//char	*str;
	t_data	data;

	(void)argc;
	(void)argv;
	(void)env;

	copy_env(env, data.env);
	if (argc != 1)
	{
		data.token = NULL;
		data.cmd = NULL;
		return (run_non_interactive(argv[1], &data));
	}
	
	
	rl_clear_history();
	return (0);
}
