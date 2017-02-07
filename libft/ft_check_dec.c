/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:01:25 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/03 18:02:55 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		contain_only_zero(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void			ft_check_dec(t_pf **pf)
{
	char *tmp;

	if ((*pf)->flag_dot == 1 && (contain_only_zero((*pf)->result)))
	{
		if ((*pf)->width == 0)
		{
			free((*pf)->result);
			(*pf)->result = ft_strnew(0);
		}
		else if ((*pf)->precision == 0)
		{
			tmp = ft_strnew((*pf)->width);
			ft_memset(tmp, ' ', ft_strlen((*pf)->result));
			free((*pf)->result);
			(*pf)->result = ft_strdup(tmp);
			ft_strdel(&(tmp));
		}
	}
}
