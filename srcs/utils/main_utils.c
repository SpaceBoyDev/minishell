/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:54:02 by dario             #+#    #+#             */
/*   Updated: 2025/09/01 13:13:04 by dario            ###   ########.fr       */
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

void	setup_signal_handler(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handler;
	sigaction(SIGINT, &sa, NULL);
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
		if (!check_quotes(line))
			error_exit("quotation error");
		data->token = tokenize(line, data->last_status);
		if (!data->token)
			error_exit("tokenizing error");
		data->cmd = pipeline_cmd(data->token);
		if (!data->cmd)
			error_exit("cmd build error");
		create_processes(data->cmd, data->env);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
