/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:07:27 by marcolop          #+#    #+#             */
/*   Updated: 2025/06/22 14:07:27 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	print_token(t_token	*token)
{
	if (token->type == STR)
		printf("STR: ");
	else if (token->type == PIPE)
	{
		printf("PIPE\n");
		return ;
	}
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

void	print_tokens(t_token	*token)
{
	while (token)
	{
		print_token(token);
		token = token->next;
	}
}

void	print_cmds(t_cmd	*cmd)
{
	while (cmd)
	{
		print_cmd(cmd);
		cmd = cmd->next;
		if (cmd)
			printf("-----PIPE-----\n");
	}
}

void	print_cmd(t_cmd	*cmd)
{
	int	i;

	if (cmd->infile)
	{
		if (cmd->in == IN)
			printf("IN ");
		else
			printf("HEREDOC ");
		printf("%s\n", cmd->infile);
	}
	if (cmd->outfile)
	{
		if (cmd->out == OUT)
			printf("OUT ");
		else
			printf("APPEND ");
		printf("%s\n", cmd->outfile);
	}
	if (!cmd->args)
		return ;
	printf("cmd: ");
	i = 0;
	while (cmd->args[i])
	{
		printf("%s ", cmd->args[i]);
		i++;
	}
	printf("\n");
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
