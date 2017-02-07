/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:09:52 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 16:53:13 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_unicode(unsigned char *tab, size_t size)
{
	int		i;

	i = size - 1;
	while (i >= 0)
	{
		write(1, &(tab[i]), 1);
		i--;
	}
}

static int		not_unicode(wchar_t c, size_t size)
{
	if (size == 1)
	{
		ft_putchar((signed char)c);
		return (1);
	}
	return (0);
}

void			ft_printf_unicode(wchar_t c, size_t size)
{
	unsigned char		tab[size + 1];

	tab[size + 1] = '\0';
	if (not_unicode(c, size))
		return ;
	else if (size == 2)
	{
		tab[1] = (unsigned char)((c >> 6) | 0xC0);
		tab[0] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (size == 3)
	{
		tab[2] = (unsigned char)((c >> 12) | 0xE0);
		tab[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		tab[0] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (size == 4)
	{
		tab[3] = (unsigned char)(((c >> 18) & 0x7) | 0xF0);
		tab[2] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		tab[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		tab[0] = (unsigned char)((c & 0x3F) | 0x80);
	}
	print_unicode(tab, size);
}

void			ft_printf_str_unicode(wchar_t *str)
{
	while (*str)
	{
		ft_printf_unicode((*str), ft_wcharlen(*str));
		str++;
	}
}
