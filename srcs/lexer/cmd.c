/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:42:42 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/10 19:42:44 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "lexer.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->name = NULL;
	cmd->args = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->next = NULL;
	cmd->in_fd = -1;
	cmd->out_fd = -1;
	return (cmd);
}

t_cmd	*build_cmd(t_token	*token)
{
	t_cmd	*cmd;

	cmd = init_cmd();
	if (!cmd)
		return (NULL);
	if (!args_cmd(cmd, token))
		return (NULL);
	// TODO: check returns of these fts
	in_cmd(cmd, token);
	out_cmd(cmd, token);
	return (cmd);
}

t_cmd	*pipeline_cmd(t_token *token)
{
	t_cmd	*first;
	t_cmd	*cmd;

	first = build_cmd(token);
	if (!first)
		return (NULL);
	cmd = first;
	while (token)
	{
		while (token && token->type != PIPE)
			token = token->next;
		if (token)
		{
			token = token->next;
			if (!token)
				return (NULL);
		}
		else
			return (first);
		cmd->next = build_cmd(token);
		if (!cmd->next)
			return (NULL);
		cmd = cmd->next;
	}
	return (first);
}

int	args_ret(t_token *token, t_cmd *cmd, char **args, int cnt)
{
	while (token && token->type != PIPE)
	{
		if (token->type == STR)
		{
			args[cnt] = ft_strdup(token->str);
			if (!args[cnt])
				return (0);
			cnt++;
		}
		token = token->next;
	}
	cmd->args = args;
	cmd->name = args[0];
	return (1);
}

int	args_cmd(t_cmd *cmd, t_token *token)
{
	int		cnt;
	t_token	*tmp;
	char	**args;

	cnt = 0;
	tmp = token;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == STR)
			cnt++;
		tmp = tmp->next;
	}
	if (cnt == 0)
		return (0);
	args = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!args)
		return (0);
	args[cnt] = NULL;
	cnt = 0;
	return (args_ret(token, cmd, args, cnt));
}
