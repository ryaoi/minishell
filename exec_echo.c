/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:28:05 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/10 20:36:27 by ryaoi            ###   ########.fr       */
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

	if (cmds[1] != NULL && cmds[1][0] == '\'')
	{
		str = inspectquote(cmds, '\'');
		ft_putstr(str);
		ft_strdel(&str);
	}
	else if (cmds[1] != NULL)
		print_echo(cmds, msh);
	ft_putchar('\n');
}
