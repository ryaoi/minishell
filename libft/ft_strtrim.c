/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:02:49 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/07 19:38:13 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*no_string(void)
{
	char		*str;

	str = ft_strnew(0);
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char		*str;
	size_t		begin;
	size_t		end;

	begin = 0;
	if (s == NULL)
		return (no_string());
	while ((s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
			&& s[begin] != '\0')
		begin++;
	if (s[begin] == '\0')
		return (no_string());
	end = ft_strlen(s);
	while ((s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			&& (end - 1) > 0)
		end--;
	str = ft_strnew(end - begin + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strsub(s, begin, end - begin);
	str[end - begin + 1] = '\0';
	return (str);
}
