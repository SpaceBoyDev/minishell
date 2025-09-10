/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:39:00 by dario             #+#    #+#             */
/*   Updated: 2025/09/10 13:07:22 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

// Builtins Utils
int		is_builtin(char *str);
int		exec_builtins(t_data *data);

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