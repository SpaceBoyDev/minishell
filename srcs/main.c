/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/08/29 14:04:52 by darmarti         ###   ########.fr       */
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

void	execute_input(char *str, t_data *data)
{
	g_running_cmd = 1;
	data->last_status = create_processes(data->cmd, data->env);
	g_running_cmd = 0;
	free(str);
	token_free(data->token);
	cmd_free(data->cmd);
}

int	tokenize_input(char *str, t_data *data)
{
	if (!check_quotes(str))
	{
		free(str);
		ft_putstr_fd("quotation error\n", 2);
		return (1);
	}
	data->token = tokenize(str, data->last_status);
	if (!data->token)
	{
		free(str);
		ft_putstr_fd("tokenizing error\n", 2);
		return (1);
	}
	data->cmd = pipeline_cmd(data->token);
	if (!data->cmd)
	{
		free(str);
		token_free(data->token);
		ft_putstr_fd("cmd build error\n", 2);
		return (1);
	}
	return (0);
}

void	run_interactive(t_data *data)
{
	char	*str;

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
			continue;
		add_history(str);
		if (tokenize_input(str, data) == 1)
			continue ;
		execute_input(str, data);
	}
}

void	print_envx(char **env)
{
	int		i;
	int		x;

	i = 0;
	while (env[i])
	{
		x = 0;
		write(1, "declare -x ", 12);
		while (env[i][x])
		{
			write(1, &env[i][x], 1);
			if (env[i][x] == '=')
				write(1, "\"", 1);
			++x;
		}
		write(1, "\"\n", 2);
		++i;
	}
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

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	(void)env;

	init_data_env(env, &data);
	if (argc != 1)
	{
		data.token = NULL;
		data.cmd = NULL;
		return (run_non_interactive(argv[1], &data));
	}
	run_interactive(&data);
	
	rl_clear_history();
	return (0);
}
