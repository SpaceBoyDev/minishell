/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:57:59 by marcolop          #+#    #+#             */
/*   Updated: 2025/07/11 12:57:59 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	run_tests(void)
{
	printf("running tests...\n");
	// test_nbr_to_str();
	test_var_expansion();
	printf("done\n");
	printf("\n\n\n");
}

void	test_var_expansion(void)
{
	printf("-----\n");
	// printf("%s\n", expand("$SHELL", 0));
	// printf("%s\n", expand("$undefined", 0));
	// printf("%s\n", expand("$undefined   ", 0));
	// printf("%s\n", expand("    $undefined   ", 0));
	// printf("%s\n", expand("$$$$   $$ $$$", 0));
	// printf("%s\n", expand("hola$", 0));
	// printf("%s\n", expand("You are in $PWD", 0));
	// printf("%s\n", expand("$SHELL and $SHELL and $HOME$SHELL", 0));
	printf("%s\n", expand("$HOME $? $PWD", -127));
	printf("-----\n");
}

void	test_nbr_to_str(void)
{
	printf("-----\n");
	printf("%s\n", nbr_to_str(0));
	printf("%s\n", nbr_to_str(-0));
	printf("%s\n", nbr_to_str(-1));
	printf("%s\n", nbr_to_str(1));
	printf("%s\n", nbr_to_str(10466));
	printf("%s\n", nbr_to_str(500));
	printf("%s\n", nbr_to_str(-20000));
	printf("%s\n", nbr_to_str(-10424));
	printf("%s\n", nbr_to_str(2147483647));
	printf("%s\n", nbr_to_str(-2147483648));
	printf("-----\n");
}
