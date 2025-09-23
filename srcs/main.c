/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/09/23 19:05:44 by marcolop         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	(void)env;
	data.last_status = 0;
	init_data_env(env, &data);
	run_interactive(&data);
	rl_clear_history();
	return (0);
}
