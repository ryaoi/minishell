/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:53:29 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 19:18:40 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_p_zero(t_pf **pf)
{
	int					i;

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

static void		ft_print_p_space(t_pf **pf)
{
	char				*tmp;
	size_t				size;
	int					i;

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

static void		ft_printf_p_precision(t_pf **pf, unsigned long long nbr)
{
	char				*str;
	int					i;
	int					j;

	i = 0;
	j = 0;
	str = ft_strnew((*pf)->precision);
	ft_memset(str, '0', (*pf)->precision);
	i = (*pf)->precision - ft_ucount_digit_base(nbr, 16);
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

static void		put_zero(t_pf **pf)
{
	if ((*pf)->flag_dot == 1)
	{
		ft_putstr("0x");
		(*pf)->ret = 2;
	}
	else
	{
		ft_putstr("0x0");
		(*pf)->ret = 3;
	}
}

void			ft_printf_p(t_pf **pf, va_list ap)
{
	unsigned long long	nbr;

	nbr = (unsigned long long)va_arg(ap, void *);
	if (nbr == 0 && (*pf)->precision == 0 && (*pf)->width == 0)
	{
		put_zero(pf);
		return ;
	}
	(*pf)->result = ft_ulltoa_base(nbr, 16);
	if ((*pf)->precision > ft_ucount_digit_base(nbr, 16))
		ft_printf_p_precision(pf, nbr);
	if (((*pf)->width > (*pf)->precision || (*pf)->width >
		ft_count_digit_base(nbr, 16)))
		ft_print_p_space(pf);
	if (((*pf)->width > (*pf)->precision || (*pf)->width >
		ft_ucount_digit_base(nbr, 16)) && ((*pf)->flag_zero))
		ft_print_p_zero(pf);
	add_prefix_hex(pf);
	if ((*pf)->flag_minus)
		ft_stradjust(pf);
	ft_putstr((*pf)->result);
	(*pf)->ret = ft_strlen((*pf)->result);
	free((*pf)->result);
}
