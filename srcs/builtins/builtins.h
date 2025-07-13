/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:39:00 by dario             #+#    #+#             */
/*   Updated: 2025/07/13 00:00:03 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int	ft_cd(char *path);
int	ft_echo(char *str);
int	ft_env(char **env);
// TODO: exit
int	ft_export(t_cmd *cmd);
int	ft_pwd(void);
// TODO: unset

// Builtins Utils
int	exec_builtins(char *path, char **args, char **env);

#endif