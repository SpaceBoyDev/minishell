/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:39:00 by dario             #+#    #+#             */
/*   Updated: 2025/09/09 16:40:54 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

// Builtins Utils
int		is_builtin(char *str);
int		exec_builtins(t_data *data);

int		ft_cd(char *path);
int		ft_echo(char **args, t_data *data);
int		ft_env(char **env);
void	ft_exit(void);
int		ft_export(t_cmd *cmd, char **env);
int		ft_pwd(void);
int		ft_unset(t_cmd *cmd, char **env);

char	**unset_var(char *vardlt, int count, char **env, int env_len);

#endif