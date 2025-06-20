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
	// t_token *token;

	while (1)
	{
		str = readline(PS1);
		add_history(str);
		tokenize(str);
		// print_token(token);
		// token = token->next;
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
	first = create_token(&str[i], &i);
	token = first;
	print_token(first);
	// printf("last i %d\n", i);
	// printf("hey\n");
	while (str[i])
	{
		printf("inside loop\n");
		// while (str[i] == ' ')
		// 	i++;
		token->next = create_token(&str[i], &i);
		print_token(token->next);
		// printf("i var: %d\n", i);
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
	token->type = token_type(str, i);
	token->next = NULL;
	// printf("bef i %d\n", *i);
	token->str = token_str(str, i);
	// printf("aft i %d\n", *i);
	// printf("%s\n", token->str);
	return (token);
}

char	*token_str(char	*str, int *i)
{
	int		len;
	int		start;
	char	*val;

	len = 0;
	start = *i;
	if (str[*i] == '\'')
	{
		while (str[++(*i)] != '\'')
		{
			len++;
		}
		val = ft_substr(str, start, len);
	}
	else if (str[*i] == '\"')
	{
		// TODO:
		// expand $
		// take into account this way? $(xxx)
	}
	else
	{
		// printf("i: %d\n", *i);
		// printf("I am here\n");
		// printf("len: %d\n", len);
		while (!is_separator(str[*i]))
		{
			// printf("char %c int %d\n", str[*i], *i);
			(*i)++;
			len++;
		}
		// printf("out\n");
		// printf("len: %d\n", len);
		val = ft_substr(str, start, len);
	}
	while (!is_separator(str[*i]))
		(*i)++;
	return (val);
}

int	is_separator(char c)
{
	if (c == '<')
		return (1);
	if (c == '>')
		return (1);
	if (c == '|')
		return (1);
	if (c == '\"')
		return (1);
	if (c == '\'')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '\0')
		return (1);
	return 0;
}

// int	is_separator(char c)
// {
// 	if (c == '<')
// 		return (1);
// 	if (c == '>')
// 		return (1);
// 	if (c == '|')
// 		return (1);
// 	if (c == '\"')
// 		return (1);
// 	if (c == '\'')
// 		return (1);
// 	if (c == ' ')
// 		return (1);
// 	// if (c == '\0')
// 	// 	return (1);
// 	return (0);
// }

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
		(*i)++;
	else if (type == APPEND || type == HEREDOC)
		*i += 2;
	return (type);
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
