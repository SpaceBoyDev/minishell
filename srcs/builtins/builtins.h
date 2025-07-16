/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:39:00 by dario             #+#    #+#             */
/*   Updated: 2025/07/16 19:25:57 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

int	ft_cd(char *path);
int	ft_echo(char **args);
int	ft_env(char **env);
// TODO: exit
int	ft_export(t_cmd *cmd, char **env);
int	ft_pwd(void);
// TODO: unset

// Builtins Utils
int	exec_builtins(t_cmd *cmd, char **env);

#endif