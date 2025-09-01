/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:40:03 by dario             #+#    #+#             */
/*   Updated: 2025/09/01 13:49:36 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../execute/execute.h"
# include "../minishell.h"

// Main Utils
char	*prompt_rl(void);
void	start_minishell(void);
void	setup_signal_handler(void);
int		run_non_interactive(char *file, t_token *token, t_cmd *cmd, char **env,
		int last_status);

// Error Handling
void	error_msg(const char *error_message, bool simple);
void	error_exit(const char *error_message);

#endif
