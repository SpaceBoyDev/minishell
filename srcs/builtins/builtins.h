/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:39:00 by dario             #+#    #+#             */
/*   Updated: 2025/07/26 21:31:44 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

// Builtins Utils
int	exec_builtins(t_cmd *cmd, char **env);

int	ft_cd(char *path);
int	ft_echo(char **args);
int	ft_env(char **env);
// TODO: exit
int	ft_export(t_cmd *cmd, char **env);
int	ft_pwd(void);
int	ft_unset(t_cmd *cmd, char **env);

char	**unset_var(char **env, char *vardlt, int count, int env_len);

#endif