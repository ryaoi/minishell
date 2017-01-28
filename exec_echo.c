/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:28:05 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/28 21:25:35 by ryaoi            ###   ########.fr       */
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

static int		ft_putenv(char *str, t_msh *msh, int j)
{
	int			i;
	char		*env;

	i = j + 1;
	while (ft_isalpha(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '\"')
		i--;
	env = ft_strsub(str, j + 1, i - 1);
	if (search_env(env, msh->env) == 1)
		print_env(env, msh->env);
	ft_strdel(&env);
    if (str[i + 1] == '\"')
        i++;
	return (i);
}

void			sub_echo(char **cmds, int *i, int *j, int *max)
{
	int			k;

	if (cmds[*i][0] == '\'')
	{
		k = 0;
		if (*i == 1)
			k++;
		while (cmds[*i][k] != '\0')
		{
			if ((cmds[*i][k] == '\"' && cmds[*i][k - 1] == '\\')
				|| (cmds[*i][k] == '\'' && cmds[*i][k - 1] == '\\'))
				ft_putchar(cmds[*i][k]);
			else if (cmds[*i][k] != '\\' && cmds[*i][k] != '\'')
				ft_putchar(cmds[*i][k]);
			k++;
		}
	}
	else if (cmds[*i][0] == '\"')
	{
		*j = 1;
		*max = ft_strlen(cmds[*i]) - 1;
	}
	else
	{
		*j = 0;
		*max = ft_strlen(cmds[*i]);
	}
}

void			exec_echo(char **cmds, t_msh *msh)
{
	int			i;
	int			j;
	int			max;
	char		*str;

	i = 1;
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
