/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:05:16 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 17:05:51 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			count_digit(unsigned long nbr, int base)
{
	int				i;
	unsigned long	copy;
	unsigned long	base1;

	base1 = base;
	i = 1;
	copy = nbr;
	while (copy > base1 - 1)
	{
		i++;
		copy /= base1;
	}
	return (i);
}

char				*ft_ultoa_base(unsigned long nbr, int base)
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
