/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prefix_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:16:22 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 19:33:50 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_stronemove_oct(char **str)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_strnew(ft_strlen((*str)) - 1);
	ft_memset(tmp, ' ', ft_strlen((*str)));
	tmp[0] = '0';
	while (tmp[i + 1] != '\0')
	{
		tmp[i + 1] = (*str)[i];
		i++;
	}
	free(*str);
	return (tmp);
}

static char		*ft_stronemove_hex(char **str)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_strnew(ft_strlen((*str)) - 2);
	ft_memset(tmp, ' ', ft_strlen((*str)) - 1);
	tmp[0] = '0';
	tmp[1] = 'x';
	while (tmp[i + 2] != '\0')
	{
		tmp[i + 2] = (*str)[i];
		i++;
	}
	free(*str);
	return (tmp);
}

void			add_prefix_oct_add(t_pf **pf)
{
	char		*tmp;

	if ((*pf)->result[ft_strlen(((*pf)->result)) - 1] == ' ')
		tmp = ft_stronemove_oct(&(*pf)->result);
	else
	{
		tmp = ft_strjoin("0", (*pf)->result);
		free((*pf)->result);
	}
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&(tmp));
}

void			add_prefix_hex_add(t_pf **pf)
{
	char		*tmp;

	if ((*pf)->result[ft_strlen(((*pf)->result)) - 1] == ' '
		&& (*pf)->result[ft_strlen(((*pf)->result)) - 2] == ' ')
		tmp = ft_stronemove_hex(&(*pf)->result);
	else if ((*pf)->result[0] == ' ')
	{
		(*pf)->result[0] = 'x';
		tmp = ft_strjoin("0", (*pf)->result);
		free((*pf)->result);
	}
	else
	{
		tmp = ft_strjoin("0x", (*pf)->result);
		free((*pf)->result);
	}
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&(tmp));
}
