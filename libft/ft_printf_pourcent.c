/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pourcent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:59:08 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 18:36:46 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strzero(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			str[i] = '0';
		i++;
	}
	return (str);
}

static void		ft_strwidth(t_pf **pf)
{
	char		*tmp;

	tmp = ft_strnew((*pf)->width);
	ft_memset(tmp, ' ', (*pf)->width);
	if ((*pf)->flag_minus == 1)
		tmp[0] = '%';
	else
		tmp[((*pf)->width) - 1] = '%';
	if ((*pf)->flag_zero == 1)
		tmp = ft_strzero(tmp);
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&(tmp));
}

void			ft_printf_pourcent(t_pf **pf)
{
	if ((*pf)->width == 0)
	{
		(*pf)->ret = 1;
		ft_putchar('%');
	}
	else
	{
		(*pf)->ret = (*pf)->width;
		ft_strwidth(pf);
		ft_putstr((*pf)->result);
		free((*pf)->result);
	}
}
