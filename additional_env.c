/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:04:00 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/26 21:11:06 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void        set_env(char *name, char *data, t_msh **msh)
{
	t_env   *ptr;
	t_env   *new;

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
