/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 21:24:59 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/11 19:38:19 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		free_path(t_msh **msh)
{
	free((*msh)->bin_dir);
	(*msh)->bin_dir = ft_strsplit(":::", ':');
}

void			exec_unsetenv(char **cmds, t_msh **msh)
{
	t_env		*ptr;
	t_env		*prev;

	ptr = (*msh)->env;
	prev = ptr;
	while (ptr != NULL)
	{
		if (ft_strncmp(cmds[1], ptr->name, ft_strlen(cmds[1])) == 0)
		{
			prev->next = ptr->next;
			free(ptr->name);
			free(ptr->data);
			free(ptr);
			if (ft_strcmp(cmds[1], "PATH") == 0)
				free_path(msh);
			return ;
		}
		prev = ptr;
		ptr = ptr->next;
	}
}
