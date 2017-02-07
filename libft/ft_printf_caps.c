/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_caps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:03:02 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 19:44:27 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_null(t_pf **pf, wchar_t *str)
{
	if (str == NULL)
	{
		(*pf)->ret = 6;
		ft_putstr("(null)");
		return (1);
	}
	return (0);
}

void			ft_printf_caps(t_pf **pf, va_list ap)
{
	wchar_t		*str;

	str = va_arg(ap, wchar_t *);
	if (print_null(pf, str))
		return ;
	if ((*pf)->width > ft_wstrlen(str))
	{
		(*pf)->ret = (*pf)->width;
		(*pf)->result = ft_strnew((*pf)->width - ft_wstrlen(str));
		if ((*pf)->flag_zero == 0)
			ft_memset((*pf)->result, ' ', (*pf)->width - ft_wstrlen(str));
		else
			ft_memset((*pf)->result, '0', (*pf)->width - ft_wstrlen(str));
		if ((*pf)->flag_minus == 1)
		{
			ft_printf_str_unicode(str);
			ft_putstr((*pf)->result);
			return ;
		}
		else
			ft_putstr((*pf)->result);
	}
	else
		(*pf)->ret = ft_wstrlen(str);
	ft_printf_str_unicode(str);
}
