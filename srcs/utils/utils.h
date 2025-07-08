/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:40:03 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 00:15:38 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "../minishell.h"

// Main Utils
void		start_minishell(void);

// Error Handling
void		error_msg(const char *error_message, bool simple);
void		error_exit(const char *error_message);

#endif