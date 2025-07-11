/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:40:03 by dario             #+#    #+#             */
/*   Updated: 2025/07/12 00:38:18 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../execute/execute.h"
# include "../minishell.h"

// Main Utils
char	*prompt_rl(void);
void	start_minishell(void);
int		run_non_interactive(char *file, t_token *token, t_cmd *cmd, char **env);

// Error Handling
void	error_msg(const char *error_message, bool simple);
void	error_exit(const char *error_message);

#endif