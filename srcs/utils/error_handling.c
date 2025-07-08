/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:39:55 by dario             #+#    #+#             */
/*   Updated: 2025/07/09 01:11:03 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/** Prints in yellow the error message given below a red ERROR square
 * @param error_message Error message that's going to be displayed
*/
void	error_msg(const char *error_message, bool simple)
{
	if (simple)
		printf(RED"ERROR: "RST);
	else
		printf(RED"╔═══════╗\n║ ERROR ║\n╚═══════╝\n");
	if (error_message)
		printf(YELLOW"%s\n"RST, error_message);
}

/** Exits the program after printing the error message
 * @param error_message Error message that's going to be displayed
 */
void	error_exit(const char *error_message)
{
	error_msg(error_message, false);
	exit(EXIT_FAILURE);
}
