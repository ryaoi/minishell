/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:21:14 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/03 18:25:17 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		count_digit(short nbr, int base)
{
	int		i;
	short	copy;

	i = 1;
	copy = nbr;
	if (copy < 0)
		copy = -copy;
	while (copy > base - 1)
	{
		i++;
		copy /= base;
	}
	return (i);
}

static void		put_minus(char **str, short *nbr)
{
	*nbr = -(*nbr);
	(*str)[0] = '-';
}

char			*ft_htoa_base(short nbr, int base)
{
	int		size;
	int		neg;
	char	*array;
	char	*str;

	array = "0123456789abcdef";
	if (nbr == -32768)
		return (ft_strdup("-32768"));
	neg = (nbr < 0 ? 1 : 0);
	if (!(str = (char *)malloc(sizeof(char) * count_digit(nbr, base)
		+ neg + 1)))
		return (NULL);
	size = count_digit(nbr, base);
	if (neg)
		put_minus(&str, &nbr);
	str[size + neg] = '\0';
	while (size > 0)
	{
		str[size + neg - 1] = array[nbr % base];
		nbr /= base;
		size--;
	}
	return (str);
}
