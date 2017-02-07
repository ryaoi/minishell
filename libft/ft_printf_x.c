/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:53:22 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 16:58:18 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_print_x_zero(t_pf **pf)
{
	int					i;

	i = 0;
	while (((*pf)->result)[i] != '\0')
	{
		if (((*pf)->result)[i] == '+')
			((*pf)->result)[0] = '+';
		else if (((*pf)->result)[i] == '-')
			((*pf)->result)[0] = '-';
		i++;
	}
	i = 0;
	if (((*pf)->result)[0] == '-' || ((*pf)->result)[0] == '+')
		i++;
	while (((*pf)->result)[i] != '\0')
	{
		if ((((*pf)->result)[i]) > '0' && (((*pf)->result)[i]) <= '9')
			break ;
		if (((*pf)->result)[i] == ' ' || ((*pf)->result)[i] == '-'
			|| ((*pf)->result)[i] == '+')
			((*pf)->result)[i] = '0';
		i++;
	}
}

static void				ft_print_x_space(t_pf **pf)
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

static void				ft_printf_x_precision(t_pf **pf,
						unsigned long long nbr)
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

static void				pre_digit(t_pf **pf, unsigned long long nbr,
						int *flag_p)
{
	ft_printf_x_precision(pf, nbr);
	(*flag_p) = 1;
}

void					ft_printf_x(t_pf **pf, va_list ap)
{
	unsigned long long	nbr;
	int					flag_p;

	flag_p = 0;
	nbr = va_arg(ap, unsigned long long);
	ft_length_ull(pf, nbr, 16);
	if ((*pf)->precision > ft_ucount_digit_base(nbr, 16))
		pre_digit(pf, nbr, &flag_p);
	if (((*pf)->width > (*pf)->precision && (*pf)->width >
		ft_ucount_digit_base(nbr, 16)))
		ft_print_x_space(pf);
	if (((*pf)->width > (*pf)->precision || (*pf)->width >
		ft_ucount_digit_base(nbr, 16)) && ((*pf)->flag_zero)
		&& flag_p != 1 && (*pf)->flag_minus == 0)
		ft_print_x_zero(pf);
	if ((*pf)->flag_minus == 1)
		ft_stradjust(pf);
	if ((*pf)->flag_diese == 1)
		add_prefix_hex(pf);
	ft_check_hex(pf);
	ft_putstr((*pf)->result);
	(*pf)->ret = ft_strlen((*pf)->result);
	free((*pf)->result);
}
