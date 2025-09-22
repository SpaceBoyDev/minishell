/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:54:02 by dario             #+#    #+#             */
/*   Updated: 2025/09/22 22:39:27 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../heredoc/heredoc.h"
#include "../signals/signals.h"
#include "../builtins/builtins.h"

void	run_interactive(t_data *data)
{
	char	*str;
	char	*prompt;

	while (1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
		prompt = prompt_rl();
		str = readline(prompt);
		free(prompt);
		if (!str)
		{
			free_env(data);
			break ;
		}
		else if (!str[0])
			continue ;
		add_history(str);
		if (tokenize_input(str, data) == 1)
			continue ;
		execute_input(str, data);
	}
}

int	run_non_interactive(char *file, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (tokenize_input(line, data) == 1)
			continue ;
		execute_input(line, data);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

void	execute_input(char *str, t_data *data)
{
	t_cmd	*cmd_cpy;

	cmd_cpy = data->cmd;
	free(str);
	data->last_status = pipeline(data);
	token_free(data->token);
	cmd_free(cmd_cpy);
}

int	tokenize_input(char *str, t_data *data)
{
	if (!check_quotes(str))
	{
		free(str);
		ft_putstr_fd("quotation error\n", 2);
		return (1);
	}
	data->token = tokenize(str, data);
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
