
#include "minishell.h"

static int			cd_access(char *path)
{
	struct stat		fs;

	lstat(path, &fs);
	if (access(path, F_OK) != 0)
	{
		ft_printf("cd : %s: No such file or directory\n", path);
		return (0);
	}
	return (1);
}

void				cd_home(char **cmds, t_msh **msh)
{
	if (cd_access((*msh)->home) == 1)
	{
		modif_env("OLDPWD", (*msh)->pwd, msh);
		modif_env("PWD", (*msh)->home, msh);
		free((*msh)->pwd);
		(*msh)->pwd = ft_strdup((*msh)->home);
		chdir((*msh)->pwd);
	}
}

void				cd_twodot(char **cmds, t_msh **msh)
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
	if (cd_access(new) == 1)
	{
		modif_env("OLDPWD", (*msh)->pwd, msh);
		modif_env("PWD", new, msh);
		free((*msh)->pwd);
		(*msh)->pwd = ft_strdup(new);
		chdir((*msh)->pwd);
	}
	ft_strdel(&new);
}

void				exec_cd(char **cmds, t_msh **msh)
{
	if (cmds[1] == NULL)
		cd_home(cmds, msh);
	else if (ft_strcmp(cmds[1], ".") == 0)
		modif_env("OLDPWD", (*msh)->pwd, msh);
	else if (ft_strcmp(cmds[1], "..") == 0)
		cd_twodot(cmds, msh);
}
