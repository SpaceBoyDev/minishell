/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:25:45 by marcolop          #+#    #+#             */
/*   Updated: 2025/09/01 13:23:10 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*build_str(int len, int neg, int pow, int nbr)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((len + neg) * sizeof(char));
	if (!str)
		return (NULL);
	if (neg)
	{
		str[i] = '-';
		i++;
	}
	while (pow)
	{
		str[i] = (nbr / pow) + '0';
		nbr = nbr % pow;
		pow /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*nbr_to_str(int n)
{
	long	nbr;
	long	pow;
	int		neg;
	int		len;

	(void)neg;
	nbr = n;
	pow = 1;
	neg = 0;
	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		neg = 1;
	}
	while (nbr / (pow * 10) > 0)
	{
		pow *= 10;
		len++;
	}
	return (build_str(len, neg, pow, nbr));
}
