/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_capd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:32:29 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 16:49:48 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_capd_zero(t_pf **pf)
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

static void		ft_print_capd_plus(t_pf **pf)
{
	char		*tmp;

	tmp = ft_strjoin("+", (*pf)->result);
	free((*pf)->result);
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&(tmp));
}

static	void	ft_print_capd_space(t_pf **pf)
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

static void		ft_printf_capd_precision(t_pf **pf, long nbr)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str = ft_strnew((*pf)->precision);
	ft_memset(str, '0', (*pf)->precision);
	i = (*pf)->precision - ft_count_digit_base(nbr, 10);
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

void			ft_printf_capd(t_pf **pf, va_list ap)
{
	long		nbr;

	nbr = va_arg(ap, long);
	ft_length_ll(pf, nbr, 10);
	if ((*pf)->precision > ft_count_digit_base(nbr, 10))
		ft_printf_capd_precision(pf, nbr);
	if (nbr > -1 && (*pf)->flag_plus)
		ft_print_capd_plus(pf);
	if (((*pf)->width > (*pf)->precision &&
		(*pf)->width > ft_count_digit_base(nbr, 10)))
		ft_print_capd_space(pf);
	if (((*pf)->width > (*pf)->precision ||
			(*pf)->width > ft_count_digit_base(nbr, 10))
			&& ((*pf)->flag_zero))
		ft_print_capd_zero(pf);
	if ((*pf)->flag_minus == 1)
		ft_stradjust(pf);
	ft_putstr((*pf)->result);
	free((*pf)->result);
	(*pf)->ret = ft_strlen((*pf)->result);
}
