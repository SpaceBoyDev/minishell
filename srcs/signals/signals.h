/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:34:00 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 00:52:37 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include "../utils/utils.h"
# include "../minishell.h"

void	create_signal(int signo, void *handler, bool siginfo);
void	sigint_handler_default(int sigint);

#endif