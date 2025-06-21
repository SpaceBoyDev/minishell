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

int	check_quotes(char *str);
int	is_separator(char c);
t_token_type	token_type(char *str, int *i);
t_token	*create_token(char	*str, int *i);
char	*token_str(char	*str, int *i);
t_token *tokenize(char *input);
void	print_token(t_token	*token);

int	main(void)
{
	char	*str;
	t_token *token;

	while (1)
	{
		str = readline(PS1);
		add_history(str);
		// printf("%d\n", check_quotes(str));
		token = tokenize(str);
		if (!token)
			ft_putstr_fd("syntax error\n", 2);
		while (token)
		{
			print_token(token);
			token = token->next;
		}
	}
	return (0);
}

t_token *tokenize(char *input)
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
	first = create_token(str, &i);
	token = first;
	while (str[i])
	{
		token->next = create_token(str, &i);
		if (!token->next)
		{
			// TODO: free previous tokens
			return (NULL);
		}
		token = token->next;
	}
	return (first);
}


t_token	*create_token(char	*str, int *i)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->next = NULL;
	token->type = token_type(str, i);
	token->str = token_str(str, i);
	if (token->str == NULL)
		return (NULL);
	return (token);
}

char	*token_str(char	*str, int *i)
{
	int		len;
	int		start;
	char	*val;

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
		printf("single quotes\n");
		// while (str[++(*i)] != '\'')
		// {
		// 	len++;
		// }
		// val = ft_substr(str, start, len);
	}
	else if (str[*i] == '\"')
	{
		printf("double quotes\n");
		// TODO:
		// expand $
		// take into account this way? $(xxx)
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
t_token_type	token_type(char *str, int *i)
{
	t_token_type	type;

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
	if (type == IN || type == OUT)
		*i += 1;
	else if (type == APPEND || type == HEREDOC)
		*i += 2;
	return (type);
}

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

void	print_token(t_token	*token)
{
	if (token->type == STR)
		printf("STR: ");
	else if (token->type == PIPE)
		printf("PIPE: ");
	else if (token->type == IN)
		printf("IN: ");
	else if (token->type == OUT)
		printf("OUT: ");
	else if (token->type == APPEND)
		printf("APPEND: ");
	else if (token->type == HEREDOC)
		printf("HEREDOC: ");
	else
		printf("WRONG: ");
	printf("%s\n", token->str);
}

int	check_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\0')
				return (0);
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			if (str[i] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}
