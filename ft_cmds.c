/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:59:38 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/22 22:20:10 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			select_cmd(char *line, t_msh *msh)
{
	if (ft_strcmp(line, (msh->func)[0]) == 0
		|| ft_strcmp(line, (msh->func)[1]) == 0
		|| ft_strcmp(line, msh->func[2]) == 0
		|| ft_strcmp(line, msh->func[3]) == 0
		|| ft_strcmp(line, msh->func[4]) == 0
		|| ft_strcmp(line, msh->func[5]) == 0)
		return (1);
	return (0);
}

void		exec_cmd(char **cmds, t_msh **msh)
{
	if (ft_strcmp(cmds[0], (*msh)->func[0]) == 0)
		exec_echo(cmds, *msh);
	else if (ft_strcmp(cmds[0], (*msh)->func[1]) == 0)
		exec_cd(cmds, msh);
	else if (ft_strcmp(cmds[0], (*msh)->func[2]) == 0)
		exec_setenv(cmds, msh);
	else if (ft_strcmp(cmds[0], (*msh)->func[3]) == 0)
		exec_unsetenv(cmds, msh);
	else if (ft_strcmp(cmds[0], (*msh)->func[4]) == 0)
		exec_env(cmds, *msh);
}

void		cdminus(char *pwd, t_msh *msh)
{
	char	*ptr;

	if (ft_strncmp(msh->home, pwd, ft_strlen(msh->home)) == 0)
	{
		ft_putstr("~");
		ptr = ft_strsub(pwd, ft_strlen(msh->home), ft_strlen(pwd)
				- ft_strlen(msh->home));
		ft_putstr(ptr);
		ft_strdel(&ptr);
	}
	else
		ft_putstr(pwd);
	ft_putstr("\n");
}

int			parse_env(char **cmds, t_msh *msh)
{
	char	*ptr;

	if (cmds[1] == NULL)
	{
		printall_env(msh);
		return (1);
	}
	else if ((ptr = ft_strchr(cmds[1], '=')))
		return (ft_printf("Use setenv\n"));
	else if (ft_strncmp(cmds[1], "--unset", 7) == 0)
		return (ft_printf("Use unsetenv\n"));
	return (0);
}

void		check_wave(char **str, t_msh *msh)
{
	char	*tmp;
	char	*tmp_str;

	if (ft_strcmp(*str, "~") == 0)
	{
		ft_strdel(str);
		*str = ft_strdup(msh->home);
	}
	else if ((*str)[0] == '~' && (check_onewave(*str) == 1)
			&& (*str)[1] == '/')
	{
		tmp = ft_strdup(msh->home);
		tmp_str = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		ft_strdel(str);
		*str = ft_strjoin(tmp, tmp_str);
		ft_strdel(&tmp);
		ft_strdel(&tmp_str);
	}
}
