/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddonei.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:59:56 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/22 22:16:51 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*straddonefree(char *str, char c, int i)
{
	char	*stock;
	char	*result;

	stock = ft_strnew(1);
	stock[0] = c;
	result = ft_strjoini(str, stock, i);
	ft_strdel(&stock);
	return (result);
}

int			check_onewave(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '~')
			result++;
		i++;
	}
	return (result);
}
