/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:51:01 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/12 14:55:59 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "lexer.h"
#include "../utils/utils.h"
#include <stdlib.h>

char	*expand_aux(char *str, int *i, t_data *data)
{
	char	*sub;

	if (!str[(*i)++])
		return (NULL);
	else if (str[(*i)] == '?')
	{
		sub = nbr_to_str(data->last_status);
		(*i)++;
	}
	else
	{
		sub = get_env_val(get_var_name(&str[(*i)]), data);
		(*i) = skip_var_name(str, (*i));
	}
	return (sub);
}

char	*expand(char *str, t_data *data)
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
		i = len_until_char(str, i, '$');
		sub = ft_substr(str, s, i - s);
		tmp = ret;
		ret = ft_strjoin(tmp, sub);
		free(tmp);
		free(sub);
		sub = expand_aux(str, &i, data);
		if (sub == NULL)
			return (ret);
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

char	*get_env_val(char *var_name, t_data *data)
{
	char	*env_val;

	if (!var_name)
		return (NULL);
	env_val = ft_getenv(var_name, data->env);
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
