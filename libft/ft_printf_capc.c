/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_capc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:24:19 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 16:48:16 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_width_ret(t_pf **pf, int ret)
{
	(*pf)->ret = (*pf)->width;
	(*pf)->result = ft_strnew((*pf)->width - ret);
}

void			ft_printf_capc(t_pf **pf, va_list ap)
{
	wchar_t		c;
	int			ret;

	c = (unsigned int)va_arg(ap, wchar_t);
	ret = ft_wcharlen(c);
	if ((*pf)->width > ret)
	{
		ft_width_ret(pf, ret);
		if ((*pf)->flag_zero == 0)
			ft_memset((*pf)->result, ' ', (*pf)->width - ret);
		else
			ft_memset((*pf)->result, '0', (*pf)->width - ret);
		if ((*pf)->flag_minus == 1)
		{
			ft_printf_unicode(c, ft_wcharlen(c));
			ft_putstr((*pf)->result);
		}
		else
			ft_putstr((*pf)->result);
		free((*pf)->result);
	}
	else
		(*pf)->ret = ft_wcharlen(c);
	if ((*pf)->flag_minus == 0)
		ft_printf_unicode(c, ft_wcharlen(c));
}
