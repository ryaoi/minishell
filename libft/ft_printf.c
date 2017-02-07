/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:47:41 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 19:52:40 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				match_flag(const char *p, t_pf **pf)
{
	int			p_move;

	p_move = 0;
	while (*p == ' ' || *p == '+' || *p == '-' || *p == '#' || *p == '0')
	{
		if ((*p) == ' ')
			(*pf)->flag_space = 1;
		else if ((*p) == '+')
			(*pf)->flag_plus = 1;
		else if ((*p) == '-')
			(*pf)->flag_minus = 1;
		else if ((*p) == '#')
			(*pf)->flag_diese = 1;
		else
			(*pf)->flag_zero = 1;
		p++;
		p_move++;
	}
	return (p_move);
}

int				match_specifer_2(const char *p, t_pf **pf)
{
	if ((*p) == 'x')
		(*pf)->specifer = 'x';
	else if ((*p) == 'u')
		(*pf)->specifer = 'u';
	else if ((*p) == 'U')
		(*pf)->specifer = 'U';
	else if ((*p) == 'X')
		(*pf)->specifer = 'X';
	else if ((*p) == 'c')
		(*pf)->specifer = 'c';
	else if ((*p) == 'C')
		(*pf)->specifer = 'C';
	else if ((*p) == '%')
		(*pf)->specifer = '%';
	if ((*pf)->specifer == '0')
		return (0);
	else
		return (1);
}

int				match_specifer(const char *p, t_pf **pf)
{
	(*pf)->skip = (*pf)->skip + match_flag(p, pf);
	p = p + match_flag(p, pf);
	(*pf)->skip = (*pf)->skip + check_width(p, pf);
	p = p + check_width(p, pf);
	(*pf)->skip = (*pf)->skip + check_precision(p, pf);
	p = p + check_precision(p, pf);
	(*pf)->skip = (*pf)->skip + check_length(p, pf);
	p = p + check_length(p, pf);
	if ((*p) == 's')
		(*pf)->specifer = 's';
	else if ((*p) == 'S')
		(*pf)->specifer = 'S';
	else if ((*p) == 'p')
		(*pf)->specifer = 'p';
	else if ((*p) == 'd')
		(*pf)->specifer = 'd';
	else if ((*p) == 'D')
		(*pf)->specifer = 'D';
	else if ((*p) == 'i')
		(*pf)->specifer = 'i';
	else if ((*p) == 'o')
		(*pf)->specifer = 'o';
	else if ((*p) == 'O')
		(*pf)->specifer = 'O';
	return (match_specifer_2(p, pf));
}

static	void	case_nothing(const char **format, size_t *ret)
{
	ft_putchar(**format);
	(*ret)++;
	(*format)++;
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_pf		*pf;
	size_t		ret;

	ret = 0;
	if (only_pourcent(format) != 2)
		return (only_pourcent(format));
	va_start(ap, format);
	while (*format != '\0')
	{
		pf = init_pf();
		if (*format != '%')
			case_nothing(&format, &ret);
		else if (match_specifer((++format), &pf))
		{
			select_specifer(&pf, ap);
			ret = ret + pf->ret;
			format = format + pf->skip + 1;
		}
		free(pf);
	}
	va_end(ap);
	return (ret);
}
