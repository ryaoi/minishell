/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:36:47 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/30 16:57:33 by ryaoi            ###   ########.fr       */
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

static void			cd_files(char **cmds, t_msh **msh)
{
	char	*path;

	path = NULL;
	path = ft_strjoin((*msh)->pwd, "/");
	path = ft_strjoini(path, cmds[1], 1);
	if (check_file(path, cmds[1]) == 0)
	{
		modif_env("OLDPWD", (*msh)->pwd, msh);
		free((*msh)->pwd);
		modif_env("PWD", path, msh);
		(*msh)->pwd = ft_strdup(path);
	}
	free(path);
}

static void			cd_dir(char **cmds, t_msh **msh)
{
	char	*path;

	if (cmds[1][0] == '~')
		path = ft_strjoin((get_data("HOME", (*msh)->env)), (cmds[1] + 1));
	else
		path = ft_strdup(cmds[1]);
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
	if (cmds[1] == NULL)
		cd_home(msh);
	else if (ft_strcmp(cmds[1], ".") == 0)
		modif_env("OLDPWD", (*msh)->pwd, msh);
	else if (ft_strcmp(cmds[1], "..") == 0)
		cd_twodot(msh);
	else if (cmds[1][0] == '/' || cmds[1][0] == '~')
		cd_dir(cmds, msh);
	else if (cmds[1][0] != '/')
		cd_files(cmds, msh);
}
