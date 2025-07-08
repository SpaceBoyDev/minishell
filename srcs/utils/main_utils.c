/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:54:02 by dario             #+#    #+#             */
/*   Updated: 2025/07/08 23:14:22 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.h"
# include "../signals/signals.h"

void	start_minishell(void)
{
	struct sigaction	sa;
	
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;	
}

// void	ft_start_gigachell(void)
// {
// 	struct sigaction	sa;

// 	signal(SIGINT, ft_handle_sigint_normal);
// 	signal(SIGTERM, SIG_IGN);
// 	signal(SIGQUIT, SIG_IGN);
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = 0;
// 	sa.sa_handler = ft_handle_sigint_normal;
// 	if (sigaction(SIGINT, &sa, NULL) == -1)
// 		ft_error("Failed sigaction");
// }