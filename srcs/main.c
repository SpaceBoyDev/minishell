/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:10 by dario             #+#    #+#             */
/*   Updated: 2025/06/10 17:50:57 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/lexer.h"
#include "minishell.h"

#define PS1 "minishell> "

int	main(void)
{
	char	*str;
	t_token	*token;
	t_cmd	*cmd;

	while (1)
	{
		str = readline(PS1);
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
			return (0);
		}
		// print_cmd(cmd);
		print_cmds(cmd);
	}
	return (0);
}
