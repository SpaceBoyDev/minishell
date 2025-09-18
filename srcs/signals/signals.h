/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:34:00 by dario             #+#    #+#             */
/*   Updated: 2025/09/18 13:52:33 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include "../utils/utils.h"
# include "../minishell.h"

# define HEREDOC_ERR 255

void	handler(int sig);
void	heredoc_handler(int sig);

#endif
