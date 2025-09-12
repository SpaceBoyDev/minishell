/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:16:06 by dario             #+#    #+#             */
/*   Updated: 2025/09/12 19:38:35 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "lexer.h"

int	is_separator(char c)
{
	if (c == '|')
		return (1);
	if (c == '<')
		return (1);
	if (c == '>')
		return (1);
	if (c == '\"')
		return (1);
	if (c == '\'')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

char	*str_no_quotes_opt(char *str, int *i, int start)
{
	int		len;
	char	*val;

	len = 0;
	while (!is_separator(str[*i]))
	{
		(*i)++;
		len++;
	}
	val = ft_substr(str, start, len);
	if (!val)
		return (NULL);
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	return (val);
}

char	*str_quotes_opt(char *str, int *i, int start)
{
	char	c;
	int		len;
	char	*val;

	len = 0;
	c = str[*i];
	start++;
	while (str[++(*i)] != c)
		len++;
	(*i)++;
	val = ft_substr(str, start, len);
	if (!val)
		return (NULL);
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	return (val);
}

char	*build_val(char *str, int *i, t_data *data)
{
	t_build_tkn	build_tkn;

	build_tkn.start = *i;
	build_tkn.val = NULL;
	if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
		return (NULL);
	else if (str[*i] == '\'' || str[*i] == '\"')
	{
		build_tkn.tmp_char = str[*i];
		build_tkn.val = str_quotes_opt(str, i, build_tkn.start);
		if (build_tkn.tmp_char == '\"')
		{
			build_tkn.tmp = build_tkn.val;
			build_tkn.val = expand(build_tkn.tmp, data);
			free(build_tkn.tmp);
		}
	}
	else
	{
		build_tkn.tmp = str_no_quotes_opt(str, i, build_tkn.start);
		build_tkn.val = expand(build_tkn.tmp, data);
		free(build_tkn.tmp);
	}
	return (build_tkn.val);
}

char	*token_str(char	*str, int *i, t_data *data)
{
	char	*val;

	while (str[*i] && str[*i] == ' ')
		(*i)++;
	if (!str[*i])
		return (NULL);
	val = build_val(str, i, data);
	return (val);
}
