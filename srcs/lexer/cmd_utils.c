/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:01:16 by dario             #+#    #+#             */
/*   Updated: 2025/09/22 22:34:05 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "lexer.h"

int	len_until_char(char *str, int i, char character)
{
	while (str[i] && str[i] != character)
		i++;
	return (i);
}

int	in_cmd(t_cmd *cmd, t_token *token)
{
	t_token	*key;

	key = NULL;
	while (token && token->type != PIPE)
	{
		if (token->type == IN || token->type == HEREDOC)
			key = token;
		token = token->next;
	}
	if (!key)
		return (1);
	cmd->in_op = key->type;
	cmd->infile = ft_strdup(key->str);
	if (!cmd->infile)
		return (0);
	return (1);
}

int	out_cmd(t_cmd *cmd, t_token *token)
{
	t_token	*key;

	key = NULL;
	while (token && token->type != PIPE)
	{
		if (token->type == OUT || token->type == APPEND)
			key = token;
		token = token->next;
	}
	if (!key)
		return (1);
	cmd->out_op = key->type;
	cmd->outfile = ft_strdup(key->str);
	if (!cmd->outfile)
		return (0);
	return (1);
}

void	table_free(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
}

void	cmd_free(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		if (cmd->infile)
		{
			free(cmd->infile);
			cmd->infile = NULL;
		}
		if (cmd->outfile)
		{
			free(cmd->outfile);
			cmd->outfile = NULL;
		}
		table_free(cmd->args);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
	cmd = NULL;
}
