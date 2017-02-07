/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:18:42 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/06 14:27:53 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		count_digit(int nbr)
{
	int		i;
	long	copy;

	i = 1;
	copy = nbr;
	if (copy < 0)
		copy = -copy;
	while (copy > 9)
	{
		i++;
		copy /= 10;
	}
	return (i);
}

char			*ft_itoa(int nbr)
{
	long	i;
	int		size;
	int		negative;
	char	*str;

	i = nbr;
	negative = (nbr < 0 ? 1 : 0);
	str = (char *)malloc(sizeof(char) * count_digit(nbr) + negative + 1);
	if (str == NULL)
		return (NULL);
	size = count_digit(nbr);
	if (negative)
	{
		i = -i;
		str[0] = '-';
	}
	while (size > 0)
	{
		str[size + negative - 1] = (i % 10) + '0';
		i /= 10;
		size--;
	}
	str[count_digit(nbr) + negative] = '\0';
	return (str);
}
