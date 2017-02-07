/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:38:09 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 18:51:49 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_null(t_pf **pf)
{
	(*pf)->ret = 6;
	ft_putstr("(null)");
}

int				first_check_s(t_pf **pf, char **str, va_list ap)
{
	if (ft_strcmp((*pf)->length, "l") == 0)
	{
		ft_printf_caps(pf, ap);
		return (1);
	}
	(*str) = va_arg(ap, char *);
	if ((*str) == NULL)
	{
		print_null(pf);
		return (1);
	}
	return (0);
}
