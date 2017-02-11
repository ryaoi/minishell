/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getquotezero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:24:50 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/10 19:58:49 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*getquote(char **cmds, int size)
{
	char	*result;
	char	*ret;
	int		i;

	i = 0;
	result = ft_strnew(size);
	while (cmds[i] && size > 0)
	{
		if ((size_t)size >= ft_strlen(cmds[i]))
			result = ft_strjoini(result, cmds[i], 1);
		else
			ft_strncat(result, cmds[i], size);
		size -= ft_strlen(cmds[i]);
		i++;
		if (cmds[i] != NULL)
		{
			ret = ft_strdup(result);
			ft_strdel(&result);
			result = ft_strjoin(ret, " ");
			ft_strdel(&ret);
		}
	}
	ret = ft_strsub(result, 1, ft_strlen(result) - 2);
	ft_strdel(&result);
	return (ret);
}

char		*inspectquotezero(char **cmds, char c)
{
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 0;
	while (cmds[i])
	{
		j = 0;
		if (i == 0)
			j++;
		while (cmds[i][j] != '\0')
		{
			if (cmds[i][j] == c && i != 0 && j != 0)
				break ;
			j++;
			size++;
		}
		i++;
		size++;
	}
	return (getquote(cmds, size));
}
