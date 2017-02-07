/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:17:38 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 19:15:09 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		c_strcopy(t_pf **pf, unsigned char c, size_t n)
{
	size_t			i;

	if (n == 1)
		(*pf)->result[0] = c;
	else
	{
		i = ((*pf)->width - 1);
		((*pf)->result)[i] = c;
	}
}

static void			just_print(t_pf **pf, unsigned char c)
{
	(*pf)->ret = 1;
	ft_putchar(c);
}

void				ft_printf_c(t_pf **pf, va_list ap)
{
	unsigned char	c;

	if (ft_strcmp((*pf)->length, "l") == 0)
	{
		ft_printf_capc(pf, ap);
		return ;
	}
	c = (unsigned char)va_arg(ap, int);
	if ((*pf)->width > 1)
	{
		(*pf)->ret = (*pf)->width;
		(*pf)->result = ft_strnew((*pf)->width);
		if ((*pf)->flag_zero == 0)
			ft_memset((*pf)->result, ' ', (*pf)->width);
		else
			ft_memset((*pf)->result, '0', (*pf)->width);
		if ((*pf)->flag_minus == 1)
			c_strcopy(pf, c, 1);
		else
			c_strcopy(pf, c, 0);
		ft_putstr((*pf)->result);
		free((*pf)->result);
	}
	else
		just_print(pf, c);
}
