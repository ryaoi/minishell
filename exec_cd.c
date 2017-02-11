/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:36:47 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/11 16:31:53 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			cd_home(t_msh **msh)
{
	struct stat		fs;

	lstat((*msh)->home, &fs);
	if (check_directory((*msh)->home) == 0)
	{
		modif_env("OLDPWD", (*msh)->pwd, msh);
		modif_env("PWD", (*msh)->home, msh);
		free((*msh)->pwd);
		(*msh)->pwd = ft_strdup((*msh)->home);
		chdir((*msh)->pwd);
	}
}

static void			cd_twodot(t_msh **msh)
{
	int		i;
	char	*new;

	i = ft_strlen((*msh)->pwd);
	while (i > 0)
	{
		if (((*msh)->pwd)[i] == '/')
			break ;
		i--;
	}
	if (i != 0)
		new = ft_strsub((*msh)->pwd, 0, i);
	else
		new = ft_strdup("/");
	if (check_directory(new) == 0)
	{
		modif_env("OLDPWD", (*msh)->pwd, msh);
		modif_env("PWD", new, msh);
		free((*msh)->pwd);
		(*msh)->pwd = ft_strdup(new);
	}
	ft_strdel(&new);
}

static void			cd_files(char *str, t_msh **msh)
{
	char	*path;

	path = NULL;
	path = ft_strjoin((*msh)->pwd, "/");
	path = ft_strjoini(path, str, 1);
	if (check_file(path, str) == 0)
	{
		modif_env("OLDPWD", (*msh)->pwd, msh);
		free((*msh)->pwd);
		modif_env("PWD", path, msh);
		(*msh)->pwd = ft_strdup(path);
	}
	free(path);
}

static void			cd_dir(char *str, t_msh **msh)
{
	char	*path;

	if (str[0] == '~')
		path = ft_strjoin((get_data("HOME", (*msh)->env)), (str + 1));
	else
		path = ft_strdup(str);
	if (check_directory(path) == 0)
	{
		modif_env("OLDPWD", (*msh)->pwd, msh);
		free((*msh)->pwd);
		modif_env("PWD", path, msh);
		(*msh)->pwd = ft_strdup(path);
	}
	free(path);
}

void				exec_cd(char **cmds, t_msh **msh)
{
	char	*str;

	if (cmds[1] == NULL)
	{
		cd_home(msh);
		return ;
	}
	if (cmds[1][0] == '\"')
		str = inspectquote(cmds, '\"');
	else if (cmds[1][0] == '\'')
		str = inspectquote(cmds, '\'');
	else
		str = ft_strdup(cmds[1]);
	if (ft_strcmp(str, ".") == 0)
		modif_env("OLDPWD", (*msh)->pwd, msh);
	else if (ft_strcmp(str, "..") == 0)
		cd_twodot(msh);
	else if (str[0] == '/' || str[0] == '~')
		cd_dir(str, msh);
	else if (str[0] != '/')
		cd_files(str, msh);
	ft_strdel(&str);
}
