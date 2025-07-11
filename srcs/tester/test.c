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
	printf("-----\n");
	test_var_expansion();
	printf("finished\n");
	printf("-----\n\n\n");
}

void	test_var_expansion(void)
{
	printf("%s\n", expand("$SHELL"));
	printf("%s\n", expand("$undefined"));
	printf("%s\n", expand("$undefined   "));
	printf("%s\n", expand("    $undefined   "));
	printf("%s\n", expand("$$$$   $$ $$$"));
	printf("%s\n", expand("hola$"));
	printf("%s\n", expand("You are in $PWD"));
	printf("%s\n", expand("$SHELL and $SHELL and $HOME$SHELL"));
	printf("%s\n", expand("$SHELL"));
}
