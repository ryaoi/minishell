/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:04:00 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/18 17:18:42 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		replace_envdata(char *name, char *data, t_msh **msh, int modif)
{
	t_env	*ptr;

	ptr = (*msh)->env;
	while (ptr && (ft_strcmp(name, ptr->name) != 0))
		ptr = ptr->next;
	if (ptr == NULL)
		return ;
	free(ptr->data);
	ptr->data = ft_strdup(data);
	ptr->modif = modif;
	if (ft_strcmp(name, "PATH") == 0)
	{
		freecmds((*msh)->bin_dir);
		(*msh)->bin_dir = ft_strsplit(ptr->data, ':');
	}
}

static void	renewall_path(t_msh **msh, char *data)
{
	freecmds((*msh)->bin_dir);
	(*msh)->bin_dir = ft_strsplit(data, ':');
}

void		set_env(char *name, char *data, t_msh **msh, int modif)
{
	t_env	*ptr;
	t_env	*new;

	if (search_env(name, (*msh)->env) == 1)
	{
		replace_envdata(name, data, msh, modif);
		return ;
	}
	if (!(new = (t_env *)malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(name);
	new->data = ft_strdup(data);
	new->modif = modif;
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
	if (ft_strcmp(name, "PATH") == 0)
		renewall_path(msh, data);
}

void		env_string_err(char *str, t_msh *msh)
{
	ft_putstr("env: ");
	print_doubledot(str, msh, 0, 0);
	ft_putendl(": No such file or directory");
}

int			env_error(char *str)
{
	struct stat fs;

	lstat(str, &fs);
	if (access(str, F_OK) != 0)
		return ((ft_printf("env : %s: No such file or directory\n", str)));
	else
		return ((ft_printf("env : %s: Permission denied\n", str)));
	ft_strdel(&str);
}
