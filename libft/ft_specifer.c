/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:11:31 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 19:28:10 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_specifer(t_pf **pf, va_list ap)
{
	if ((*pf)->specifer == 's')
		ft_printf_s(pf, ap);
	else if ((*pf)->specifer == 'c')
		ft_printf_c(pf, ap);
	else if ((*pf)->specifer == '%')
		ft_printf_pourcent(pf);
	else if ((*pf)->specifer == 'd')
		ft_printf_d(pf, ap);
	else if ((*pf)->specifer == 'o')
		ft_printf_o(pf, ap);
	else if ((*pf)->specifer == 'x')
		ft_printf_x(pf, ap);
	else if ((*pf)->specifer == 'p')
		ft_printf_p(pf, ap);
	else if ((*pf)->specifer == 'u')
		ft_printf_u(pf, ap);
	else
		select_specifer_two(pf, ap);
}

void	select_specifer_two(t_pf **pf, va_list ap)
{
	if ((*pf)->specifer == 'X')
		ft_printf_capx(pf, ap);
	else if ((*pf)->specifer == 'C')
		ft_printf_capc(pf, ap);
	else if ((*pf)->specifer == 'S')
		ft_printf_caps(pf, ap);
	else if ((*pf)->specifer == 'i')
		ft_printf_d(pf, ap);
	else if ((*pf)->specifer == 'U')
		ft_printf_capu(pf, ap);
	else if ((*pf)->specifer == 'O')
		ft_printf_capo(pf, ap);
	else
		ft_printf_capd(pf, ap);
}
