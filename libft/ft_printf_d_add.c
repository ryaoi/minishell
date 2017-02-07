/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:13:40 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 18:25:56 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_case_plus(t_pf **pf)
{
	int		i;

	i = 0;
	while (((*pf)->result)[i++] != '\0')
	{
		if (((*pf)->result)[i] == '-')
			return (1);
	}
	if (((*pf)->result)[0] == ' ')
	{
		i = 0;
		while (((*pf)->result)[i] == ' ')
			i++;
		((*pf)->result)[i - 1] = '+';
		return (1);
	}
	if (((*pf)->result)[0] == '0' && ft_strcmp((*pf)->result, "0") != 0)
	{
		((*pf)->result)[0] = '+';
		return (1);
	}
	return (0);
}

void		ft_d_final_check(t_pf **pf, long long nbr)
{
	ft_check_dec(pf);
	ft_put_space(pf, nbr);
}
