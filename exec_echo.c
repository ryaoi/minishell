/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:28:05 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/29 22:44:43 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			print_env(char *str, t_env *env)
{
	t_env		*ptr;

	ptr = env;
	while (ptr != NULL)
	{
		if (ft_strcmp(str, ptr->name) == 0)
		{
			ft_putstr(ptr->data);
			return ;
		}
		ptr = ptr->next;
	}
}

int				search_env(char *str, t_env *env)
{
	t_env		*ptr;

	ptr = env;
	while (ptr != NULL)
	{
		if (ft_strcmp(str, ptr->name) == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void			exec_echo(char **cmds, t_msh *msh)
{
	char		*str;

	if (cmds[1] != NULL && cmds[1][0] == '\"')
	{
		str = inspectquote(cmds, '\"');
		print_doubledot(str, msh, 0, 0);
	}
	else if (cmds[1] != NULL && cmds[1][0] == '\'')
	{
		str = inspectquote(cmds, '\'');
		ft_putstr(str);
	}
	else if (cmds[1] != NULL)
	{
		str = ft_strsub(cmds[1], 1, ft_strlen(cmds[1]));
		if (ft_strchr(cmds[1], '$') == NULL)
			ft_putstr(cmds[1]);
		else if (search_env(str, msh->env) == 1)
			print_env(str, msh->env);
	}
	ft_putchar('\n');
}
