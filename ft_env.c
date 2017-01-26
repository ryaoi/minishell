/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:11:37 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/26 21:23:09 by ryaoi            ###   ########.fr       */
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

static void	not_dollar(int *j, int *i, char **result, char **str)
{
	if ((*str)[*i] != '$')
	{
		(*result)[*j] = (*str)[*i];
		(*j)++;
		(*i)++;
	}
}

static void	get_good_env(char **str, char **data, int *k, int *i)
{
	*k = *i;
	while ((*str)[*k] >= 'A' && (*str)[*k] <= 'Z')
		(*k)++;
	(*k) -= (*i);
	(*data) = ft_strsub(*str, *i, *k);
}

char		*get_str_env(char *str, int size, t_msh **msh, int i)
{
	char	*result;
	char	*data;
	int		k;
	int		j;

	j = 0;
	k = 0;
	result = (char *)malloc(sizeof(char) * (size + 1));
	while (str[i + 1] != '\0')
	{
		if (str[i] == '$' &&
			(size = check_env_name(str, ++i, (*msh)->env) != 0))
		{
			get_good_env(&str, &data, &k, &i);
			ft_strncpy(&((result)[j]), get_data(data,
			(*msh)->env), check_env_name(str, i, (*msh)->env));
			free(data);
			j += check_env_name(str, i, (*msh)->env);
			while (str[i] >= 'A' && str[i] <= 'Z')
				i++;
		}
		not_dollar(&j, &i, &result, &str);
	}
	result[j] = '\0';
	return (result);
}
