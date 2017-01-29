/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:11:37 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/29 22:00:26 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		modif_env(char *name, char *new_data, t_msh **msh)
{
	t_env	*ptr;

	ptr = (*msh)->env;
	while (ptr != NULL)
	{
		if (ft_strcmp(ptr->name, name) == 0)
		{
			free(ptr->data);
			ptr->data = ft_strdup(new_data);
			return ;
		}
		ptr = ptr->next;
	}
}

char		*get_data(char *name, t_env *env)
{
	t_env	*ptr;

	ptr = env;
	while (ptr != NULL)
	{
		if (ft_strcmp(name, ptr->name) == 0)
			return (ptr->data);
		ptr = ptr->next;
	}
	return (NULL);
}

char		*get_str_env(char *str, int size, t_msh **msh)
{
	char	*result;
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(str, ' ');
	result = ft_strnew(size);
	while(split[i] != 0)
	{
		if (search_env(split[i] + 1, (*msh)->env) == 1)
			ft_strcat(result, get_data(split[i] + 1, (*msh)->env));
		else
			ft_strcat(result, split[i]);
		free(split[i]);
		i++;
		if (split[i] != 0)
			ft_strcat(result, " ");
	}
	free(split);
	return (result);
}
