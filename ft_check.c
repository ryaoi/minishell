/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:03:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/17 01:54:59 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				check_quote(char *str)
{
	char		*tmp;

	if (str[0] == '\"' || str[0] == '\'')
		tmp = ft_strsub(str, 1, ft_strlen(str) - 2);
	else
		tmp = ft_strdup(str);
	if (stronly(tmp, ' ') == 1)
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

int				check_file(char *path, char *file)
{
	struct stat	fs;

	lstat(path, &fs);
	if (access(path, F_OK) != 0)
	{
		ft_putstr("minishell: ");
		return ((ft_printf("cd: %s: No such file or directory\n", file)));
	}
	else if ((fs.st_mode & S_IXUSR) == 0 && (S_ISDIR(fs.st_mode)))
	{
		ft_putstr("minishell: ");
		return ((ft_printf("cd: %s: Permission denied\n", file)));
	}
	else if (!(S_ISDIR(fs.st_mode)) && !(S_ISLNK(fs.st_mode)))
	{
		ft_putstr("minishell: ");
		return ((ft_printf("cd: %s: Not a directory\n", file)));
	}
	return (0);
}

int				check_directory(char *path)
{
	struct stat	fs;

	lstat(path, &fs);
	if (access(path, F_OK) != 0)
	{
		ft_putstr("minishell: ");
		return ((ft_printf("cd: %s: No such file or directory\n", path)));
	}
	else if ((fs.st_mode & S_IXUSR) == 0 && (S_ISDIR(fs.st_mode)))
	{
		ft_putstr("minishell: ");
		return ((ft_printf("cd: %s: Permission denied\n", path)));
	}
	else if (!(S_ISDIR(fs.st_mode)) && !(S_ISLNK(fs.st_mode)))
	{
		ft_putstr("minishell ");
		return ((ft_printf("cd: %s: Not a directory\n", path)));
	}
	return (0);
}

void			check_space(char **cmds)
{
	char		*str;

	str = NULL;
	if (cmds[0][0] == '\"' || cmds[0][0] == '\'')
	{
		if (cmds[0][0] == '\"')
			str = inspectquotezero(cmds, '\"');
		if (cmds[0][0] == '\'')
			str = inspectquotezero(cmds, '\'');
		if (ft_strchr(str, ' ') != NULL)
		{
			ft_printf("minishell: %s: command not found\n", str);
			ft_strdel(&str);
			freecmds(cmds);
			exit(0);
		}
		ft_strdel(&str);
	}
}

int				stronly(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
