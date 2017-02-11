/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 19:45:02 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/11 18:54:54 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		init_pwd(t_msh **msh, char **envp)
{
	int			i;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp("PWD", envp[i], 3) == 0)
			(*msh)->pwd = ft_strsub(envp[i], 4, ft_strlen(envp[i]));
		if (ft_strncmp("HOME", envp[i], 4) == 0)
			(*msh)->home = ft_strsub(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
}

static void		add_env(t_env **head, char *str)
{
	t_env		*ptr;
	t_env		*new;
	char		**tmp;

	tmp = ft_strsplit(str, '=');
	if (!(new = (t_env *)malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(tmp[0]);
	new->data = ft_strdup(tmp[1]);
	new->modif = 0;
	freecmds(tmp);
	new->next = NULL;
	if ((*head) == NULL)
	{
		*head = new;
		return ;
	}
	ptr = (*head);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

static void		init_env(t_msh **msh, char **envp)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "SHLVL", 5) == 0)
			add_env(&((*msh)->env), "SHLVL=2");
		else
			add_env(&((*msh)->env), envp[i]);
		i++;
	}
}

static void		init_bin_dir(t_msh **msh, char **envp)
{
	char		*str;

	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	str = ft_strsub(*envp, 5, ft_strlen(*envp));
	(*msh)->bin_dir = ft_strsplit(str, ':');
	ft_strdel(&str);
}

void			init_msh(t_msh **msh, char **envp)
{
	if (!((*msh) = (t_msh *)malloc(sizeof(t_msh))))
		exit(EXIT_FAILURE);
	if (!((*msh)->func = (char **)malloc(sizeof(char *) * 7)))
		exit(EXIT_FAILURE);
	(*msh)->func[0] = ft_strdup("echo");
	(*msh)->func[1] = ft_strdup("cd");
	(*msh)->func[2] = ft_strdup("setenv");
	(*msh)->func[3] = ft_strdup("unsetenv");
	(*msh)->func[4] = ft_strdup("env");
	(*msh)->func[5] = ft_strdup("exit");
	(*msh)->func[6] = 0;
	(*msh)->env = NULL;
	(*msh)->process = 0;
	init_env(msh, envp);
	init_bin_dir(msh, envp);
	init_pwd(msh, envp);
	replace_envdata("SHELL", get_data("PWD", (*msh)->env), msh, 0);
}
