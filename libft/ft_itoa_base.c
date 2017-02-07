/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:27:46 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 19:21:02 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		count_digit(int nbr, int base)
{
	int		i;
	int		copy;

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

static void		put_minus(char **str, int *nbr)
{
	*nbr = -(*nbr);
	(*str)[0] = '-';
}

char			*ft_itoa_base(int nbr, int base)
{
	int		size;
	int		neg;
	char	*array;
	char	*str;

	array = "0123456789abcdef";
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
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
