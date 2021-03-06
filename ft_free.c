/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:02:25 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/17 04:41:04 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		freecmds(char **cmds)
{
	int		i;

	i = 0;
	while (cmds[i] != 0)
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void		freeenv(t_env **env)
{
	t_env	*ptr;
	t_env	*curr;

	ptr = *env;
	while (ptr != NULL)
	{
		curr = ptr->next;
		free(ptr->name);
		free(ptr->data);
		free(ptr);
		ptr = curr;
	}
	(*env) = NULL;
}

void		freemsh(t_msh **msh)
{
	freeenv(&(*msh)->env);
	freecmds((*msh)->func);
	freecmds((*msh)->bin_dir);
	free((*msh)->pwd);
	free((*msh)->home);
	free((*msh)->opwd);
}

void		exec_exit(char **cmds, t_msh **msh, char **full_cmd)
{
	freecmds(cmds);
	freecmds(full_cmd);
	freemsh(msh);
	reset_term(*msh);
	free(*msh);
	exit(EXIT_SUCCESS);
}
