/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:00:05 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/10 21:30:57 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_right_env(char *name, t_env *env)
{
	t_env	*ptr;

	ptr = env;
	while (ptr != NULL)
	{
		if (ft_strcmp(ptr->name, name) == 0 && ptr->modif == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static int	check_existenv(t_msh *msh, int *i, char **buff, char *str)
{
	char	*name;
	int		j;

	j = *i + 1;
	while (str[j] >= 'A' && str[j] <= 'Z')
		j++;
	j -= *i + 1;
	name = ft_strsub(str, *i + 1, j);
	if (search_right_env(name, msh->env) == 1)
	{
		*buff = ft_strjoini(*buff, get_data(name, msh->env), 1);
		ft_strdel(&name);
		*i = *i + j;
		return (1);
	}
	ft_strdel(&name);
	return (0);
}

char		*envtostr(char *str, int i, t_msh **msh)
{
	char	*buff;

	buff = ft_strnew(1);
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			if (check_existenv(*msh, &i, &buff, str) != 1)
				buff = straddonefree(buff, str[i], 1);
		}
		else
			buff = straddonefree(buff, str[i], 1);
		i++;
	}
	return (buff);
}
