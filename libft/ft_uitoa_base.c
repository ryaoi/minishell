/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:04:02 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 17:04:18 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			count_digit(unsigned int nbr, int base)
{
	int				i;
	unsigned int	copy;
	unsigned int	base1;

	i = 1;
	base1 = base;
	copy = nbr;
	while (copy > base1 - 1)
	{
		i++;
		copy /= base1;
	}
	return (i);
}

char				*ft_uitoa_base(unsigned int nbr, int base)
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
