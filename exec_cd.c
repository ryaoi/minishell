/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:36:47 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/17 05:18:00 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			cd_home(t_msh **msh)
{
	struct stat		fs;

	if (get_data("HOME", (*msh)->env) == NULL)
	{
		env_pwdopwd((*msh)->pwd, (*msh)->pwd, msh);
		return ;
	}
	lstat((*msh)->home, &fs);
	if (check_directory((*msh)->home) == 0)
	{
		env_pwdopwd((*msh)->home, (*msh)->pwd, msh);
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
		env_pwdopwd(new, (*msh)->pwd, msh);
	ft_strdel(&new);
}

static void			cd_files(char *str, t_msh **msh)
{
	char	*path;

	path = NULL;
	if (ft_strcmp((*msh)->pwd, "/") != 0)
		path = ft_strjoin((*msh)->pwd, "/");
	else
		path = ft_strdup("/");
	path = ft_strjoini(path, str, 1);
	if (path[ft_strlen(path) - 1] == '/')
		path = ft_strsubfree(path, 0, ft_strlen(path) - 2);
	if (check_file(path, str) == 0)
		env_pwdopwd(path, (*msh)->pwd, msh);
	free(path);
}

static void			cd_dir(char *str, t_msh **msh)
{
	char	*path;

	if (ft_strcmp(str, "-") == 0)
	{
		env_pwdopwd((*msh)->pwd, (*msh)->opwd, msh);
		swap_pwdopwd(msh);
		return ;
	}
	else if (str[0] == '~' && (get_data("HOME", (*msh)->env) == NULL))
	{
		env_pwdopwd((*msh)->pwd, (*msh)->pwd, msh);
		return ;
	}
	if (str[0] == '~')
		path = ft_strjoin((get_data("HOME", (*msh)->env)), (str + 1));
	else
		path = ft_strdup(str);
	if (check_directory(path) == 0)
		env_pwdopwd(path, (*msh)->pwd, msh);
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
		env_pwdopwd((*msh)->pwd, (*msh)->pwd, msh);
	else if (ft_strcmp(str, "..") == 0)
		cd_twodot(msh);
	else if (str[0] == '/' || str[0] == '~' || ft_strcmp(str, "-") == 0)
		cd_dir(str, msh);
	else if (str[0] != '/')
		cd_files(str, msh);
	chdir((*msh)->pwd);
	ft_strdel(&str);
}
