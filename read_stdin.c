/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:24:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/07 21:19:01 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int			read_stdin(char **line)
{
	int		ret;
	char	buf[1];
	char	*str;
	int		flag;

	flag = 0;
	ret = 0;
	str = ft_strnew(0);
	while ((ret = read(1, buf, 1) > 0) && *buf != '\n')
	{
		flag = 1;
		buf[ret] = '\0';
		if (buf[0] != '\t')
			str = ft_strjoini(str, buf, 1);
	}
	*line = ft_strdup(str);
	ft_strdel(&str);
	if (*buf == '\n' && flag == 0)
		return (0);
	return (ret);
}
