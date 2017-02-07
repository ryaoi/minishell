/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/30 19:46:35 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words_spec(char const *s, char c)
{
	int			i;
	int			result;
	int			state;
	int			laststate;

	i = 0;
	result = 0;
	state = 0;
	laststate = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			state = 1;
		if (s[i] == c)
			state = 0;
		if (state != laststate && state == 1)
			result++;
		laststate = state;
		i++;
	}
	return (result);
}

static	int		size_words(char const *s, char c)
{
	int			result;

	result = 0;
	while (*s != '\0' && *s != c)
	{
		result++;
		s++;
	}
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			words;
	int			i;

	if (s == NULL)
		return (NULL);
	words = ft_count_words_spec(s, c);
	str = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (size_words(s, c) != 0)
		{
			str[i] = ft_strsub(s, 0, size_words(s, c));
			i++;
			s = s + size_words(s, c);
		}
	}
	str[i] = 0;
	return (str);
}
