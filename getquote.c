/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getquote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:24:50 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/29 22:50:55 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*getquote(char **cmds, int size, char c)
{
	char	*result;
	char	*ret;
	int		i;

	i = 1;
	result = ft_strnew(size);
	while (cmds[i] && size > 0)
	{
		if (size >= ft_strlen(cmds[i]))
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

static char	*getquotetwo(char **cmds, int size, char c)
{
	char	*result;
	int		i;
	char	*ret;

	i = 2;
	result = ft_strnew(size);
	while (cmds[i] && size > 0)
	{
		if (size >= ft_strlen(cmds[i]))
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

char		*inspectquotetwo(char **cmds, char c)
{
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 2;
	while (cmds[i])
	{
		j = 0;
		if (i == 2)
			j++;
		while (cmds[i][j] != '\0')
		{
			if (cmds[i][j] == c && i != 2 && j != 0)
				break ;
			j++;
			size++;
		}
		i++;
		size++;
	}
	return (getquotetwo(cmds, size, c));
}
