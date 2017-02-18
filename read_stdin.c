/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:24:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/18 19:37:49 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				read_stdin(char **line)
{
	int			ret;
	char		buf[1];
	char		*str;
	int			flag;

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
	if ((*buf == '\n' && flag == 0) || stronly(*line, ' ') == 1
		|| (quotenspace(*line) == 0))
	{
		ft_strdel(line);
		return (0);
	}
	return (ret);
}

static void		print_space(char *str)
{
	if (str != NULL)
		ft_putchar(' ');
}

void			print_echo(char **cmds, t_msh *msh)
{
	int			i;
	char		*str;

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

int				check_perm(char *str, int *ret)
{
	if (access(str, F_OK) == 0)
	{
		if (access(str, X_OK) == 0)
		{
			*ret = 1;
			return (1);
		}
		else
		{
			*ret = -1;
			return (1);
		}
	}
	return (0);
}

void			cmd_dir_notfound(char **envp, char *stock, int perm)
{
	struct stat	fs;

	lstat(stock, &fs);
	freecmds(envp);
	if (perm == -1)
		ft_printf("minishell: %s: Permission denied\n", stock);
	else if (S_ISDIR(fs.st_mode))
		ft_printf("minishell: %s: is a directory\n", stock);
	else if (ft_strchr(stock + 1, '/') == NULL)
		ft_printf("minishell: %s: command not found\n", stock);
	else if (stock[0] != '$')
		ft_printf("minishell: %s: No such file or directory\n", stock);
	ft_strdel(&stock);
	exit(0);
}
