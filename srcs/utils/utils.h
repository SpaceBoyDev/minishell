/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:40:03 by dario             #+#    #+#             */
/*   Updated: 2025/09/25 17:33:21 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../execute/execute.h"
# include "../minishell.h"

// Main Utils
void	setup_signal_handler(void);
void	run_interactive(t_data *data);
int		run_non_interactive(char *file, t_data *data);
void	execute_input(char *str, t_data *data);
int		tokenize_input(char *str, t_data *data);

// Shell Utils
char	*prompt_rl(void);
void	init_data_env(char **src, t_data *data);
char	*ft_getenv(char *name, char **env);
int		ft_strcmp(char *s1, char *s2);
void	*free_return_null(void *var);

// Error Handling
void	error_msg(const char *error_message, bool simple);
void	error_exit(const char *error_message);

#endif
