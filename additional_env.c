/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:04:00 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/28 16:00:08 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		replace_envdata(char *name, char *data, t_env *env)
{
	t_env *ptr;

	ptr = env;
	while (ft_strcmp(name, ptr->name) != 0)
		ptr = ptr->next;
	free(ptr->data);
	printf("ptr->data gonna be:%s\n", data);
	ptr->data = ft_strdup(data);
	printf("ptr->name:%s\n", ptr->name);
	printf("ptr->data:%s\n", ptr->data);
}

void        set_env(char *name, char *data, t_msh **msh)
{
	t_env   *ptr;
	t_env   *new;

	if (search_env(name, (*msh)->env) == 1)
	{
		replace_envdata(name, data, (*msh)->env);
		return ;
	}
	if (!(new = (t_env *)malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(name);
	new->data = ft_strdup(data);
	new->next = NULL;
	if ((*msh)->env == NULL)
		(*msh)->env = new;
	else
	{
		ptr = (*msh)->env;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}
