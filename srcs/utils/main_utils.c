/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:54:02 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 01:11:37 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../signals/signals.h"

void	start_minishell(void)
{
	struct sigaction	sa;

	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &sigint_handler_default;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		error_msg("Sigaction failed", true);
}
