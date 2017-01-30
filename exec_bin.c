/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:26:08 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/30 17:58:49 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			**tab_env(t_env *env)
{
	int		i;
	t_env	*ptr;
	char	**tab;
	char	*stock;

	ptr = env;
	i = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	ptr = env;
	i = 0;
	while (ptr != NULL)
	{
		stock = ft_strjoin(ptr->name, "=");
		tab[i] = ft_strjoini(stock, ptr->data, 1);
		i++;
		ptr = ptr->next;
	}
	tab[i] = 0;
	return (tab);
}

static void			freeall(char **envp, char *stock, char *str)
{
	freecmds(envp);
	ft_strdel(&stock);
	ft_strdel(&str);
}

static void			cmd_notfound(char **envp, char *stock)
{
	freecmds(envp);
	ft_printf("minishell: command not found: %s\n", (stock + 1));
	ft_strdel(&stock);
	exit(0);
}

void				exec_bin(char **cmds, t_msh *msh)
{
	int		i;
	char	*str;
	char	*stock;
	char	**envp;

	i = 0;
	chdir(msh->pwd);
	envp = tab_env(msh->env);
	stock = ft_strjoin("/", cmds[0]);
	while ((msh->bin_dir)[i] != 0)
	{
		str = ft_strjoin((msh->bin_dir)[i], stock);
		free(cmds[0]);
		cmds[0] = ft_strdup(str);
		if (execve(str, &cmds[0], envp) > 0)
		{
			freeall(cmds, stock, str);
			exit(0);
		}
		i++;
		ft_strdel(&str);
	}
	cmd_notfound(envp, stock);
}
