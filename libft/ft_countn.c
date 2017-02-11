/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:12:21 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/11 20:13:15 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countn(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return (i);
}