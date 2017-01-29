/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getquote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:24:50 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/29 16:27:27 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*getquote(char **cmds, int size, char c)
{
	char	*result;
	int		i;

	i = 1;
	result = ft_strnew(size);
	while (cmds[i] && size > 0)
	{
		if (size >= ft_strlen(cmds[i]))
			ft_strcat(result, cmds[i]);
		else
			ft_strncat(result, cmds[i], size);
		size -= ft_strlen(cmds[i]);
		i++;
		if (cmds[i] != NULL)
			result = ft_strjoini(result, " ", 1);
	}
	result = ft_strsubfree(result, 1, ft_strlen(result) - 2);
	return (result);
}

char		*inspectquote(char **cmds, char c)
{
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 1;
	while (cmds[i])
	{
		j = 0;
		if (i == 1)
			j++;
		while (cmds[i][j] != '\0')
		{
			if (cmds[i][j] == c && i != 1 && j != 0)
				break ;
			j++;
			size++;
		}
		i++;
		size++;
	}
	return (getquote(cmds, size, c));
}
