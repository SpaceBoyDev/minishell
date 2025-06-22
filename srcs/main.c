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

#include "minishell.h"
#include <readline/history.h>

#define PS1 "minishell> "

t_token_type	token_type(char *str, int *i);
t_token	*create_token(char	*str, int *i);
char	*token_str(char	*str, int *i);
t_token *tokenize(char *input);

int	main(void)
{
	char	*str;
	t_token *token;

	while (1)
	{
		str = readline(PS1);
		add_history(str);
		if (!check_quotes(str))
		{
			ft_putstr_fd("syntax error (quotes)\n", 2);
			continue ;
		}
		token = tokenize(str);
		if (!token)
			ft_putstr_fd("syntax error\n", 2);
		print_tokens(token);
	}
	return (0);
}




