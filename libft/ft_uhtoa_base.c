/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uhtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:03:38 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 17:03:49 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		count_digit(unsigned short nbr, int base)
{
	int				i;
	unsigned short	copy;

	i = 1;
	copy = nbr;
	while (copy > base - 1)
	{
		i++;
		copy /= base;
	}
	return (i);
}

char			*ft_uhtoa_base(unsigned short nbr, int base)
{
	int				size;
	char			*array;
	char			*str;

	array = "0123456789abcdef";
	if (!(str = (char *)malloc(sizeof(char) * count_digit(nbr, base) + 1)))
		return (NULL);
	size = count_digit(nbr, base);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = array[nbr % base];
		nbr /= base;
		size--;
	}
	return (str);
}
