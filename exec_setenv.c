/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:27:28 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/27 18:59:04 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		all_cap(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (1);
		i++;
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
		return (ft_printf("Missing the name of the variable to set and the value of the variable\n"));
	else if (i < 3)
		return (ft_printf("Missing the value of the variable\n"));
	else if (all_cap(cmds[1]))
		return (ft_printf("The name of the variable shoud be capitalized\n"));
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
	printf("result is:%s\n", result);
	if (search_env(result, env) == 1)
		ret = ft_strlen(get_data(result, env));
	return (ret);
}

static char		*replace_env(char *str, t_msh **msh)
{
	int			i;
	int			size;

	i = 1;
	size = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == '$' && (size += check_env_name(str, ++i, (*msh)->env)) != 0)
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
	return (get_str_env(str, size, msh, 1));
}

void			exec_setenv(char **cmds, t_msh **msh)
{
	char		*data;

	if (check_cmds(cmds) > 0)
		return ;
	if (cmds[2][0] == '\'')
		data = ft_strsub(cmds[2], 1, (ft_strlen(cmds[2])) - 2);
	else if (cmds[2][0] == '\"' && ft_strchr(cmds[2], '$') != NULL)
		data = replace_env(cmds[2], msh);
	else if (cmds[2][0] == '\"')
		data = ft_strsub(cmds[2], 1, (ft_strlen(cmds[2])) - 2);
	else
		data = ft_strdup(cmds[2]);
	set_env(cmds[1], data, msh);
	ft_strdel(&data);
}
