/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:11:59 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/03 18:20:14 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		count_digit(char nbr, int base)
{
	int		i;
	char	copy;

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

static void		put_minus(char **str, char *nbr)
{
	*nbr = -(*nbr);
	(*str)[0] = '-';
}

char			*ft_hhtoa_base(char nbr, int base)
{
	int		size;
	int		neg;
	char	*array;
	char	*str;

	array = "0123456789abcdef";
	if (nbr == -128)
		return (ft_strdup("-128"));
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
