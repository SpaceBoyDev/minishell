/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:30:31 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/24 19:03:43 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (sub)
			sub = ft_strdup(sub);
		(*i) = skip_var_name(str, (*i));
	}
	return (sub);
}

char	*expand(char *str, t_data *data)
{
	t_expand_var	var;

	var.ret = NULL;
	var.i = 0;
	while (str[var.i])
	{
		var.s = var.i;
		var.i = len_until_char(str, var.i, '$');
		var.sub = ft_substr(str, var.s, var.i - var.s);
		var.tmp = var.ret;
		var.ret = ft_strjoin(var.tmp, var.sub);
		free(var.tmp);
		free(var.sub);
		var.sub = expand_aux(str, &var.i, data);
		if (var.sub == NULL)
			return (var.ret);
		var.tmp = var.ret;
		var.ret = ft_strjoin(var.tmp, var.sub);
		free(var.sub);
		free(var.tmp);
	}
	return (var.ret);
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
