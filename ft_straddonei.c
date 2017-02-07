/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddonei.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:59:56 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/07 19:59:58 by ryaoi            ###   ########.fr       */
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
