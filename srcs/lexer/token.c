/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:15:22 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/12 14:36:32 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "lexer.h"

t_token	*tokenize(char *input, t_data *data)
{
	int		i;
	char	*str;
	t_token	*token;
	t_token	*first;

	str = ft_strtrim(input, " ");
	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (NULL);
	i = 0;
	first = create_token(str, &i, data);
	if (!first)
		return (NULL);
	token = first;
	while (str[i])
	{
		token->next = create_token(str, &i, data);
		if (!token->next)
			return (NULL);
		token = token->next;
	}
	free(str);
	return (first);
}

t_token	*create_token(char	*str, int *i, t_data *data)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->next = NULL;
	token->type = token_type(str, i);
	if (token->type != PIPE)
	{
		token->str = token_str(str, i, data);
		if (token->str == NULL)
			return (NULL);
	}
	return (token);
}

void	skip(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}

// sets type of token
// moves i to the char after operator if not STR
t_op	token_type(char *str, int *i)
{
	t_op	type;

	skip(str, i);
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

void	token_free(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		if (token->type != PIPE)
			free(token->str);
		tmp = token;
		token = token->next;
		free(tmp);
	}
}
