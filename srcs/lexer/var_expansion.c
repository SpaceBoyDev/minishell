/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:51:01 by marcolop          #+#    #+#             */
/*   Updated: 2025/06/22 17:51:01 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "lexer.h"
#include <stdlib.h>

char	*expand(char *str, int last_status)
{
	int		i;
	int		s;
	char	*ret;
	char	*sub;
	char	*tmp;

	ret = NULL;
	i = 0;
	while (str[i])
	{
		s = i;
		while (str[i] && str[i] != '$')
			i++;
		sub = ft_substr(str, s, i - s);
		tmp = ret;
		ret = ft_strjoin(tmp, sub);
		free(tmp);
		free(sub);
		if (!str[i++])
			return (ret);
		else if (str[i] == '?')
		{
			sub = nbr_to_str(last_status);
			i++;
		}
		else
		{
			// TODO: see below statements
			// keep in mind the skip change since '?'
			sub = get_env_val(get_var_name(&str[i]));
			i = skip_var_name(str, i);
		}
		tmp = ret;
		ret = ft_strjoin(tmp, sub);
		free(tmp);
	}
	return (ret);
}

char	*get_var_name(char *str)
{
	int	i;

	if (!str[0] || !(ft_isalpha(str[0]) || str[0] == '_'))
		return (NULL);
	i = 1;
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			break ;
		i++;
	}
	return (ft_substr(str, 0, i));
}

char	*get_env_val(char *var_name)
{
	char	*env_val;

	if (!var_name)
		return (NULL);
	env_val = getenv(var_name);
	free(var_name);
	return (env_val);
}

int	skip_var_name(char *str, int i)
{

	if (!(str[i] && (ft_isalpha(str[i]) || str[i] == '_')))
		return (i);
	i++;
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			break ;
		i++;
	}
	return (i);
}
