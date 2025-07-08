/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:33:49 by dario             #+#    #+#             */
/*   Updated: 2025/07/08 18:45:29 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	signal_kill(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
		error_exit("Signal kill failed");
}

void	create_signal(int signo, void *handler, bool siginfo)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	if (siginfo)
		sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signo, &sa, NULL) < 0)
		error_exit("Sigaction failed");
}