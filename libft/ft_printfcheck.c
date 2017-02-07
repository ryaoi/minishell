/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:55:39 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 19:19:15 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_width(const char *p, t_pf **pf)
{
	int		result;
	int		p_move;

	p_move = 0;
	result = 0;
	if (*p == '0')
		return (p_move);
	while (ft_isdigit((*p)))
	{
		result = result * 10 + ((*p) - '0');
		p++;
		p_move++;
	}
	(*pf)->width = result;
	return (p_move);
}

int			check_precision(const char *p, t_pf **pf)
{
	int		result;
	int		p_move;

	p_move = 0;
	result = 0;
	if ((*p) == '.')
	{
		(*pf)->flag_dot = 1;
		p++;
		p_move++;
		while (ft_isdigit((*p)))
		{
			result = result * 10 + ((*p) - '0');
			p++;
			p_move++;
		}
		(*pf)->precision = result;
	}
	return (p_move);
}

int			check_length(const char *p, t_pf **pf)
{
	if ((p[0]) == 'l' && (p[1]) == 'l')
	{
		(*pf)->length = "ll";
		return (2);
	}
	else if ((p[0]) == 'h' && (p[1]) == 'h')
	{
		(*pf)->length = "hh";
		return (2);
	}
	else if ((p[0]) == 'h' || (p[0]) == 'l' || (p[0]) == 'z' || (p[0]) == 'j')
	{
		if ((p[0]) == 'h')
			(*pf)->length = "h";
		if ((p[0]) == 'l')
			(*pf)->length = "l";
		if ((p[0]) == 'z')
			(*pf)->length = "z";
		if ((p[0]) == 'j')
			(*pf)->length = "j";
		return (1);
	}
	else
		return (0);
}
