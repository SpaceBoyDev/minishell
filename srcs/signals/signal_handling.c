/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:33:49 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 01:10:45 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

extern volatile sig_atomic_t int_flag;

void	handler(int sig)
{
	(void)sig;
	int_flag = 1;
	write(1, "\n", 1);
	// TODO: make it work properly
	// it should work with nested minishells
	// rl_replace_line("", 0);
	// rl_on_new_line();
	// rl_redisplay();
}
