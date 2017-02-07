/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:05:30 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 16:45:12 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf		*init_pf(void)
{
	t_pf	*new;

	if (!(new = (t_pf *)malloc(sizeof(t_pf))))
		return (NULL);
	new->specifer = '0';
	new->flag_diese = 0;
	new->flag_space = 0;
	new->flag_minus = 0;
	new->flag_plus = 0;
	new->flag_zero = 0;
	new->flag_dot = 0;
	new->width = 0;
	new->precision = 0;
	new->skip = 0;
	new->ret = 0;
	new->result = NULL;
	new->length = NULL;
	return (new);
}
