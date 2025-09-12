/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:16:06 by dario             #+#    #+#             */
/*   Updated: 2025/09/12 14:35:44 by marcos           ###   ########.fr       */
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
	char	*val;
	int		start;
	char	*tmp;
	char	tmp_char;

	start = *i;
	val = NULL;
	if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
		return (NULL);
	else if (str[*i] == '\'' || str[*i] == '\"')
	{
		tmp_char = str[*i];
		val = str_quotes_opt(str, i, start);
		if (tmp_char == '\"')
		{
			tmp = val;
			val = expand(tmp, data);
			free(tmp);
		}
	}
	else
	{
		tmp = str_no_quotes_opt(str, i, start);
		val = expand(tmp, data);
		free(tmp);
	}
	return (val);
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
