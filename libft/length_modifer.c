/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:06:36 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 19:27:44 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_length_ll(t_pf **pf, long long nbr, int base)
{
	if ((*pf)->length == NULL && (*pf)->specifer != 'D')
		(*pf)->result = ft_itoa_base((int)nbr, base);
	else if (ft_strcmp((*pf)->length, "ll") == 0
			|| ft_strcmp((*pf)->length, "z") == 0)
		(*pf)->result = ft_lltoa_base(nbr, base);
	else if ((ft_strcmp((*pf)->length, "l") == 0
			|| ft_strcmp((*pf)->length, "j") == 0) || (*pf)->specifer == 'D')
		(*pf)->result = ft_ltoa_base((long)nbr, base);
	else if (ft_strcmp((*pf)->length, "hh") == 0)
		(*pf)->result = ft_hhtoa_base((char)nbr, base);
	else
		(*pf)->result = ft_htoa_base((short)nbr, base);
}

void		ft_length_ull(t_pf **pf, unsigned long long nbr, int base)
{
	if ((*pf)->length == NULL && (*pf)->specifer != 'U'
		&& (*pf)->specifer != 'O')
		(*pf)->result = ft_uitoa_base((unsigned int)nbr, base);
	else if (ft_strcmp((*pf)->length, "ll") == 0
			|| ft_strcmp((*pf)->length, "z") == 0)
		(*pf)->result = ft_ulltoa_base(nbr, base);
	else if (ft_strcmp((*pf)->length, "l") == 0
			|| ft_strcmp((*pf)->length, "j") == 0
			|| (*pf)->specifer == 'U' || (*pf)->specifer == 'O')
		(*pf)->result = ft_ultoa_base((unsigned long)nbr, base);
	else if (ft_strcmp((*pf)->length, "hh") == 0)
		(*pf)->result = ft_uhhtoa_base((unsigned char)nbr, base);
	else
		(*pf)->result = ft_uhtoa_base((unsigned short)nbr, base);
}

long long	select_length_d(t_pf **pf, va_list ap)
{
	if ((*pf)->length == NULL)
		return (va_arg(ap, signed int));
	else if (ft_strcmp((*pf)->length, "ll") == 0
			|| ft_strcmp((*pf)->length, "z") == 0)
		return (va_arg(ap, long long));
	else if (ft_strcmp((*pf)->length, "l") == 0
			|| ft_strcmp((*pf)->length, "j") == 0)
		return (va_arg(ap, long));
	else if (ft_strcmp((*pf)->length, "hh") == 0)
		return (va_arg(ap, int));
	else if (ft_strcmp((*pf)->length, "h") == 0)
		return (va_arg(ap, int));
	else
		return (va_arg(ap, int));
}
