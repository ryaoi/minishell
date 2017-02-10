/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerasef.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:06:19 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/10 20:39:24 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*calc_new(char *str, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			len++;
		i++;
	}
	return (ft_strnew(len));
}

char		*ft_strerasef(char *str, char c)
{
	int		i;
	int		len;
	char	*ret;

	ret = calc_new(str, c);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			ret[len] = str[i];
			len++;
		}
		i++;
	}
	free(str);
	return (ret);
}
