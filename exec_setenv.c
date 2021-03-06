/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:27:28 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/22 00:51:04 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		all_cap(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
			i++;
		else
			return (1);
	}
	return (0);
}

static int		check_cmds(char **cmds)
{
	int		i;

	i = 0;
	while (cmds[i])
		i++;
	if (i < 2)
	{
		ft_putstr("Missing the name of the variable");
		return (ft_printf(" and the value of the variable\n"));
	}
	else if (i < 3)
		return (ft_printf("Missing the value of the variable\n"));
	else if (ft_strisalpha(cmds[1]))
	{
		ft_putstr("The name of the variable");
		return (ft_printf(" should only contain characters\n"));
	}
	else if (all_cap(cmds[1]))
		return (ft_printf("The name of the variable shoud be capitalized\n"));
	else if (stronly(cmds[1], '_') == 1)
	{
		ft_putstr("The name of the variable");
		return (ft_printf(" should contain a letter\n"));
	}
	return (0);
}

int				check_env_name(char *str, int i, t_env *env)
{
	char		*result;
	int			j;
	int			ret;

	ret = 0;
	j = i;
	while ((str[j] >= 'A' && str[j] <= 'Z'))
		j++;
	j -= i;
	result = ft_strsub(str, i, j);
	if (search_env(result, env) == 1)
		ret = ft_strlen(get_data(result, env));
	ft_strdel(&result);
	return (ret);
}

static char		*replace_env(char *str, t_msh **msh)
{
	int			i;
	int			size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' &&
			(size += check_env_name(str, ++i, (*msh)->env)) != 0)
		{
			while (str[i] >= 'A' && str[i] <= 'Z' && str[i] != '\0')
				i++;
		}
		else
		{
			i++;
			size++;
		}
	}
	return (get_str_env(str, size, msh));
}

void			exec_setenv(char **cmds, t_msh **msh)
{
	char		*data;
	char		*str;

	if (check_cmds(cmds) > 0)
		return ;
	if (cmds[2][0] == '\'')
		data = inspectquotetwo(cmds, '\'');
	else if (cmds[2][0] == '\"')
	{
		str = inspectquotetwo(cmds, '\"');
		data = replace_env(str, msh);
		ft_strdel(&str);
	}
	else if (ft_strchr(cmds[2], '$') == NULL)
		data = ft_strdup(cmds[2]);
	else if (search_env((cmds[2] + 1), (*msh)->env) == 1)
		data = ft_strdup(get_data((cmds[2] + 1), (*msh)->env));
	if (search_env(cmds[1], (*msh)->env) == 1)
		replace_envdata(cmds[1], data, msh,
		((ft_strchr(cmds[2], '\'') != NULL) ? 1 : 0));
	else
		set_env(cmds[1], data, msh,
		((ft_strchr(cmds[2], '\'') != NULL) ? 1 : 0));
	ft_strdel(&data);
}
