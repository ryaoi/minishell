/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:58:56 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 17:00:22 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_space(t_pf **pf, long long nbr)
{
	int	i;

	i = 0;
	if ((*pf)->width > ft_count_digit_base(nbr, 10)
		&& (*pf)->flag_plus == 0 && (*pf)->flag_space == 1)
		((*pf)->result)[i] = ' ';
	else if ((*pf)->flag_space == 1 && (*pf)->flag_minus == 0 &&
		(*pf)->flag_plus == 0 && (*pf)->width == 0 && nbr >= 0)
	{
		ft_putchar(' ');
		(*pf)->ret++;
		i++;
	}
}
