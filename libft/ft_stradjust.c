/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:01:42 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 17:01:44 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_stradjust(t_pf **pf)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_strnew(ft_strlen((*pf)->result));
	ft_memset(tmp, ' ', ft_strlen((*pf)->result));
	j = 0;
	i = 0;
	while (((*pf)->result)[i] == ' ')
		i++;
	while (((*pf)->result)[i] != '\0')
	{
		tmp[j] = ((*pf)->result)[i];
		j++;
		i++;
	}
	free((*pf)->result);
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&tmp);
}
