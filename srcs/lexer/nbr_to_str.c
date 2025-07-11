/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:25:45 by marcolop          #+#    #+#             */
/*   Updated: 2025/07/11 13:25:45 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*nbr_to_str(int n)
{
	long	nbr;
	long	pow;
	int		neg;
	int		len;
	int		i;
	char	*str;

	(void)neg;
	nbr = n;
	pow = 1;
	neg = 0;
	len = 1;
	i = 0;
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
		// printf("%ld ", nbr / pow);
		str[i] = (nbr / pow) + '0';
		nbr = nbr % pow;
		pow /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
