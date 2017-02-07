/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:09:36 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/10 19:30:56 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_digit_base(long long nbr, int base)
{
	int					i;
	long long			copy;
	long long			base1;

	i = 1;
	copy = nbr;
	base1 = base;
	if (copy < 0)
		copy = -copy;
	while (copy > base1 - 1)
	{
		i++;
		copy /= base1;
	}
	return (i);
}

int		ft_ucount_digit_base(unsigned long long nbr, int base)
{
	int					i;
	unsigned long long	copy;
	unsigned long long	base1;

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

int		ft_digit(long long nbr, int base)
{
	int					i;
	long long			copy;
	long long			base1;

	i = 1;
	copy = nbr;
	base1 = base;
	if (copy < 0)
		copy = -copy;
	while (copy > base1 - 1)
	{
		i++;
		copy /= base1;
	}
	return (i);
}
