/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:15:22 by marcolop          #+#    #+#             */
/*   Updated: 2025/06/22 14:15:22 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "lexer.h"

t_token *tokenize(char *input, int last_status)
{
	int		i;
	char	*str;
	t_token	*token;
	t_token	*first;

	str = ft_strtrim(input, " ");
	free(input);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (NULL); // TODO: empty str
	i = 0;
	first = create_token(str, &i, last_status);
	token = first;
	while (str[i])
	{
		token->next = create_token(str, &i, last_status);
		if (!token->next)
		{
			// TODO: free previous tokens
			return (NULL);
		}
		token = token->next;
	}
	return (first);
}


t_token	*create_token(char	*str, int *i, int last_status)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->next = NULL;
	token->type = token_type(str, i);
	if (token->type != PIPE)
	{
		token->str = token_str(str, i, last_status);
		if (token->str == NULL)
			return (NULL);
	}
	return (token);
}

char	*token_str(char	*str, int *i, int last_status)
{
	int		len;
	int		start;
	char	*val;
	char	*tmp;

	while (str[*i] && str[*i] == ' ')
		(*i)++;
	if (!str[*i])
		return (NULL);
	len = 0;
	start = *i;
	if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|') {
		return (NULL);
	}
	else if (str[*i] == '\'')
	{
		start++;
		while (str[++(*i)] != '\'')
		{
			len++;
		}
		(*i)++;
		val = ft_substr(str, start, len);
		if (!val)
			return (NULL);
		while (str[*i] && str[*i] == ' ')
			(*i)++;
	}
	else if (str[*i] == '\"')
	{
		start++;
		while (str[++(*i)] != '\"')
		{
			len++;
		}
		(*i)++;
		val = ft_substr(str, start, len);
		if (!val)
			return (NULL);
		while (str[*i] && str[*i] == ' ')
			(*i)++;
		tmp = val;
		val = expand(tmp, last_status);
		free(tmp);
	}
	else
	{
		while (!is_separator(str[*i]))
		{
			(*i)++;
			len++;
		}
		val = ft_substr(str, start, len);
		if (!val)
			return (NULL); // TODO: check null ft who called
		while (str[*i] && str[*i] == ' ')
			(*i)++;
	}
	return (val);
}

// sets type of token
// moves i to the char after operator if not STR
t_op	token_type(char *str, int *i)
{
	t_op	type;

	if (str[*i] == '<' && str[*i + 1] && str[*i + 1] == '<')
		type = HEREDOC;
	else if (str[*i] == '<' && str[*i + 1] && str[*i + 1] != '<')
		type = IN;
	else if (str[*i] == '>' && str[*i + 1] && str[*i + 1] == '>')
		type = APPEND;
	else if (str[*i] == '>' && str[*i + 1] && str[*i + 1] != '>')
		type = OUT;
	else if (str[*i] == '|')
		type = PIPE;
	else
		type = STR;
	if (type == IN || type == OUT || type == PIPE)
		*i += 1;
	else if (type == APPEND || type == HEREDOC)
		*i += 2;
	return (type);
}
