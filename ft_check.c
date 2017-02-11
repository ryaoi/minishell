/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:03:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/11 14:43:36 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				check_file(char *path, char *file)
{
	struct stat	fs;

	lstat(path, &fs);
	if (access(path, F_OK) != 0)
		return ((ft_printf("cd : No such file or directory: %s\n", file)));
	else if ((fs.st_mode & S_IXUSR) == 0 && (S_ISDIR(fs.st_mode)))
		return ((ft_printf("cd : Permission denied %s\n", file)));
	else if (!(S_ISDIR(fs.st_mode)))
		return ((ft_printf("cd : not a directory: %s\n", file)));
	return (0);
}

int				check_directory(char *path)
{
	struct stat	fs;

	lstat(path, &fs);
	if (access(path, F_OK) != 0)
		return ((ft_printf("cd : No such file or directory: %s\n", path)));
	else if ((fs.st_mode & S_IXUSR) == 0 && (S_ISDIR(fs.st_mode)))
		return ((ft_printf("cd : Permission denied %s\n", path)));
	else if (!(S_ISDIR(fs.st_mode)))
		return ((ft_printf("cd : not a directory: %s\n", path)));
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
