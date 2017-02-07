/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:03:15 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/11 20:12:53 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_strcpy_width(t_pf **pf)
{
	int			i;
	int			j;
	char		*tmp;

	tmp = ft_strnew((*pf)->width);
	if ((*pf)->flag_zero == 1)
		ft_memset(tmp, '0', (*pf)->width);
	else
		ft_memset(tmp, ' ', (*pf)->width);
	i = ((*pf)->width - (int)ft_strlen((*pf)->result));
	j = 0;
	while (tmp[i] != '\0')
	{
		tmp[i] = ((*pf)->result)[j];
		i++;
		j++;
	}
	free((*pf)->result);
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static void		s_strcpy(t_pf **pf)
{
	int			i;
	char		*tmp;

	tmp = ft_strnew((*pf)->precision);
	i = 0;
	while (i < (*pf)->precision)
	{
		tmp[i] = ((*pf)->result)[i];
		i++;
	}
	free((*pf)->result);
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static void		just_print(t_pf **pf)
{
	(*pf)->ret = ft_strlen((*pf)->result);
	ft_putstr((*pf)->result);
}

static void		pre_flag_dot(t_pf **pf)
{
	free((*pf)->result);
	(*pf)->result = ft_strnew(0);
}

void			ft_printf_s(t_pf **pf, va_list ap)
{
	char		*str;

	if (first_check_s(pf, &str, ap))
		return ;
	(*pf)->result = ft_strdup(str);
	if (((*pf)->precision != 0) || ((*pf)->flag_dot) == 1 ||
		(*pf)->width > (int)ft_strlen((*pf)->result))
	{
		if ((*pf)->precision == 0 && (*pf)->flag_dot == 1)
			pre_flag_dot(pf);
		else if ((*pf)->precision != 0)
			s_strcpy(pf);
		if ((*pf)->width > (*pf)->precision || (*pf)->width >
			(int)ft_strlen(str))
			s_strcpy_width(pf);
		if ((*pf)->flag_minus != 0)
			ft_stradjust(pf);
		(*pf)->ret = ft_strlen((*pf)->result);
		ft_putstr((*pf)->result);
	}
	else
		just_print(pf);
	free((*pf)->result);
}
