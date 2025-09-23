/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:39:00 by dario             #+#    #+#             */
/*   Updated: 2025/09/23 17:34:22 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

typedef struct s_vars
{
	int		i;
	bool	next_var;
}	t_vars;

void	free_env(t_data *data);

// Builtins Utils
void	free_env(t_data *data);
int		is_builtin(char *str);
int		exec_builtins(t_data *data);

// Builtins
int		ft_cd(char *path, char **env);
int		ft_echo(char **args, t_data *data);
int		ft_env(char **env);
void	ft_exit(t_data *data);
int		ft_export(t_data *data);
int		ft_pwd(void);
int		ft_unset(t_data *data);

void	print_env(char **env);

char	**unset_var(char *vardlt, int count, char **env, int env_len);

#endif