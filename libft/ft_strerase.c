/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:06:19 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/10 20:10:07 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strerase(char *str, char c)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			len++;
		i++;
	}
	ret = ft_strnew(len);
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
	return (ret);
}
