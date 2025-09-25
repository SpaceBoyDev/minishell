/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:07:27 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/25 20:03:35 by marcolop         ###   ########.fr       */
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

int	is_empty_str(char *str)
{
	if (str[0] == '\0')
	{
		free(str);
		return (1);
	}
	return (0);
}

char	*empty_str_helper(char *str, char *ret)
{
	if (str && str[0] == '\0')
	{
		ret = (char *)malloc(sizeof(char));
		ret[0] = '\0';
		return (ret);
	}
	return (NULL);
}

void	*free_failed_token(t_token *token, char *str)
{
	token_free(token);
	free(str);
	return (NULL);
}

// void	print_token(t_token	*token)
// {
// 	if (token->type == STR)
// 		printf("STR: ");
// 	else if (token->type == PIPE)
// 	{
// 		printf("PIPE\n");
// 		return ;
// 	}
// 	else if (token->type == IN)
// 		printf("IN: ");
// 	else if (token->type == OUT)
// 		printf("OUT: ");
// 	else if (token->type == APPEND)
// 		printf("APPEND: ");
// 	else if (token->type == HEREDOC)
// 		printf("HEREDOC: ");
// 	else
// 		printf("WRONG: ");
// 	printf("%s\n", token->str);
// }

// void	print_tokens(t_token	*token)
// {
// 	while (token)
// 	{
// 		print_token(token);
// 		token = token->next;
// 	}
// }

// void	print_cmds(t_cmd	*cmd)
// {
// 	t_cmd	*og_cmd;

// 	og_cmd = cmd;
// 	while (cmd)
// 	{
// 		print_cmd(cmd);
// 		cmd = cmd->next;
// 		if (cmd)
// 			printf("-----PIPE-----\n");
// 	}
// 	cmd = og_cmd;
// }

// void	print_cmd(t_cmd	*cmd)
// {
// 	int	i;

// 	if (cmd->infile)
// 	{
// 		if (cmd->in_op == IN)
// 			printf("IN ");
// 		else
// 			printf("HEREDOC ");
// 		printf("%s\n", cmd->infile);
// 	}
// 	if (cmd->outfile)
// 	{
// 		if (cmd->out_op == OUT)
// 			printf("OUT ");
// 		else
// 			printf("APPEND ");
// 		printf("%s\n", cmd->outfile);
// 	}
// 	if (!cmd->args)
// 		return ;
// 	printf("cmd: ");
// 	i = 0;
// 	while (cmd->args[i])
// 	{
// 		printf("%s ", cmd->args[i]);
// 		i++;
// 	}
// 	printf("\n");
// }
