/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:23:40 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 19:18:34 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			add_prefix_oct(t_pf **pf)
{
	int		i;

	i = 0;
	if (((*pf)->result)[0] == ' ')
	{
		while (((*pf)->result)[i + 1] == ' ')
			i++;
		((*pf)->result)[i] = '0';
		return ;
	}
	else if (((*pf)->result)[0] == '0')
		return ;
	else
		add_prefix_oct_add(pf);
}

static void		add_zerox(int nbr, t_pf **pf)
{
	((*pf)->result)[nbr] = '0';
	((*pf)->result)[nbr + 1] = 'x';
}

void			add_prefix_hex(t_pf **pf)
{
	int		i;

	i = 0;
	if (ft_strcmp((*pf)->result, "0") == 0)
		return ;
	else if (((*pf)->result)[0] == '0' && ((*pf)->result)[1] == '0'
			&& (*pf)->precision <= (*pf)->width)
		add_zerox(0, pf);
	else if (((*pf)->result)[0] == ' ' && ((*pf)->result)[1] == ' ')
	{
		while (((*pf)->result)[i] == ' ' && ((*pf)->result)[i + 1] == ' ')
			i++;
		add_zerox(i - 1, pf);
	}
	else
		add_prefix_hex_add(pf);
}
