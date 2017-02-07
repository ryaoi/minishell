/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:01:56 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/03 15:02:06 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*src;
	char	*obj;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		src = (char *)haystack;
		obj = (char *)needle;
		while (*obj != '\0' && *src == *obj)
		{
			src++;
			obj++;
		}
		if (*obj == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
