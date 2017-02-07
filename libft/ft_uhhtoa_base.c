/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uhhtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:02:18 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 17:03:30 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			count_digit(unsigned char nbr, int base)
{
	int				i;
	unsigned char	copy;

	i = 1;
	copy = nbr;
	while (copy > base - 1)
	{
		i++;
		copy /= base;
	}
	return (i);
}

char				*ft_uhhtoa_base(unsigned char nbr, int base)
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
