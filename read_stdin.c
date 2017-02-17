/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:24:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/17 01:53:05 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_char(char *str, char c)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == c)
			ret++;
		i++;
	}
	return (ret);
}

void		check_single(char **str)
{
	char	*stock;

	stock = ft_strdup(*str);
	if (ft_strcmp(*str, "\"") == 0 || count_char(*str, '\"') == 1)
	{
		ft_strdel(str);
		*str = ft_strjoin(stock, "\"");
	}
	else if (ft_strcmp(*str, "\'") == 0 || count_char(*str, '\'') == 1)
	{
		ft_strdel(str);
		*str = ft_strjoin(stock, "\'");
	}
	ft_strdel(&stock);
}

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
	if ((*buf == '\n' && flag == 0) || stronly(*line, ' ') == 1)
	{
		ft_strdel(line);
		return (0);
	}
	return (ret);
}

static void	print_space(char *str)
{
	if (str != NULL)
		ft_putchar(' ');
}

void		print_echo(char **cmds, t_msh *msh)
{
	int		i;
	char	*str;

	i = 1;
	while (cmds[i] != 0)
	{
		if (ft_strchr(cmds[i], '\"') != NULL)
			cmds[i] = ft_strerasef(cmds[i], '\"');
		else if (ft_strchr(cmds[i], '\'') != NULL)
		{
			cmds[i] = ft_strerasef(cmds[i], '\'');
			ft_putstr(cmds[i]);
			i++;
			print_space(cmds[i]);
			continue;
		}
		str = ft_strsub(cmds[i], 1, ft_strlen(cmds[i]));
		if (ft_strchr(cmds[i], '$') == NULL)
			ft_putstr(cmds[i]);
		else if (search_env(str, msh->env) == 1)
			print_env(str, msh->env);
		ft_strdel(&str);
		i++;
		print_space(cmds[i]);
	}
}
