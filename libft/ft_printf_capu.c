/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_capu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:04:42 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 17:04:31 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_capu_zero(t_pf **pf)
{
	int			i;

	i = 0;
	while (((*pf)->result)[i] != '\0')
	{
		if (((*pf)->result)[i] == '+')
			((*pf)->result)[0] = '+';
		i++;
	}
	i = 0;
	if (((*pf)->result)[0] == '+')
		i++;
	while (((*pf)->result)[i] != '\0')
	{
		if (((*pf)->result)[i] == ' ' || ((*pf)->result)[i] == '+')
			((*pf)->result)[i] = '0';
		i++;
	}
}

static void		ft_print_capu_space(t_pf **pf)
{
	char		*tmp;
	size_t		size;
	int			i;

	tmp = ft_strnew((*pf)->width);
	ft_memset(tmp, ' ', (*pf)->width);
	size = ft_strlen((*pf)->result);
	i = (*pf)->width;
	while (size > 0)
	{
		tmp[i - 1] = ((*pf)->result)[size - 1];
		i--;
		size--;
	}
	free((*pf)->result);
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&(tmp));
}

static void		ft_printf_capu_precision(t_pf **pf, unsigned long nbr)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str = ft_strnew((*pf)->precision);
	ft_memset(str, '0', (*pf)->precision);
	i = (*pf)->precision - ft_ucount_digit_base(nbr, 10);
	while (i != (*pf)->precision)
	{
		str[i] = ((*pf)->result)[j];
		i++;
		j++;
	}
	free((*pf)->result);
	(*pf)->result = ft_strdup(str);
	ft_strdel(&(str));
}

void			ft_printf_capu(t_pf **pf, va_list ap)
{
	unsigned long nbr;

	nbr = va_arg(ap, unsigned long);
	ft_length_ull(pf, nbr, 10);
	if ((*pf)->precision > ft_ucount_digit_base(nbr, 10))
		ft_printf_capu_precision(pf, nbr);
	if (((*pf)->width > (*pf)->precision && (*pf)->width >
		ft_ucount_digit_base(nbr, 10)))
		ft_print_capu_space(pf);
	if (((*pf)->width > (*pf)->precision ||
		(*pf)->width > ft_ucount_digit_base(nbr, 10)) && ((*pf)->flag_zero))
		ft_print_capu_zero(pf);
	if ((*pf)->flag_minus == 1)
		ft_stradjust(pf);
	ft_putstr((*pf)->result);
	(*pf)->ret = ft_strlen((*pf)->result);
	free((*pf)->result);
}
