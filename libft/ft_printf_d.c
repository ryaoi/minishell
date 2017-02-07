/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:12:53 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 18:24:22 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_print_d_zero(t_pf **pf)
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
		if (((*pf)->result)[i] == ' ' ||
			((*pf)->result)[i] == '-' || ((*pf)->result)[i] == '+')
			((*pf)->result)[i] = '0';
		i++;
	}
}

static void				ft_print_d_plus(t_pf **pf)
{
	char				*tmp;

	if (ft_case_plus(pf))
		return ;
	tmp = ft_strjoin("+", (*pf)->result);
	free((*pf)->result);
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&(tmp));
}

static void				ft_print_d_space(t_pf **pf)
{
	char				*tmp;
	size_t				size;
	int					i;

	i = 0;
	tmp = ft_strnew((*pf)->width);
	if ((*pf)->flag_zero == 1 && (*pf)->flag_minus == 0
		&& (*pf)->precision == 0)
		ft_memset(tmp, '0', (*pf)->width);
	else
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

static void				ft_printf_d_precision(t_pf **pf, long long nbr)
{
	int					neg;
	char				*str;
	int					i;
	int					j;

	i = 0;
	j = 0;
	neg = (nbr < 0 ? 1 : 0);
	str = ft_strnew((*pf)->precision + neg);
	ft_memset(str, '0', (*pf)->precision + neg);
	if (neg)
	{
		str[0] = '-';
		j++;
	}
	i = (*pf)->precision + neg - ft_count_digit_base(nbr, 10);
	while (i - neg != (*pf)->precision)
	{
		str[i] = ((*pf)->result)[j];
		i++;
		j++;
	}
	free((*pf)->result);
	(*pf)->result = ft_strdup(str);
	ft_strdel(&(str));
}

void					ft_printf_d(t_pf **pf, va_list ap)
{
	long long			nbr;

	nbr = select_length_d(pf, ap);
	ft_length_ll(pf, nbr, 10);
	if ((ft_digit(nbr, 10) < (*pf)->width) || (ft_digit(nbr, 10)
		< (*pf)->precision))
	{
		if ((*pf)->width <= (*pf)->precision || ft_digit(nbr, 10)
			< (*pf)->precision)
			ft_printf_d_precision(pf, nbr);
		if ((*pf)->width > (*pf)->precision)
			ft_print_d_space(pf);
	}
	if (((*pf)->width > ft_digit(nbr, 10) && ((*pf)->flag_zero)
		&& (*pf)->flag_minus == 0 && (*pf)->precision == 0) || ((*pf)->precision
		>= ft_digit(nbr, 10) && (*pf)->precision > (*pf)->width))
		ft_print_d_zero(pf);
	if (nbr > -1 && (*pf)->flag_plus)
		ft_print_d_plus(pf);
	if ((*pf)->flag_minus == 1)
		ft_stradjust(pf);
	ft_d_final_check(pf, nbr);
	ft_putstr((*pf)->result);
	(*pf)->ret += ft_strlen((*pf)->result);
	free((*pf)->result);
}
