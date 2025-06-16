/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:04 by dario             #+#    #+#             */
/*   Updated: 2025/06/16 22:53:27 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "readline/readline.h"
#include "readline/history.h"

// Builtins
int		cd(char *path);
void	echo(char *str);
int		pwd();
// TODO: Faltan env(), exit(), export() y unset() porque hacen falta variables
