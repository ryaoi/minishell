/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pwdopwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 03:18:37 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/18 19:56:50 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			env_pwdopwd(char *pwd, char *opwd, t_msh **msh)
{
	if (pwd != NULL && (get_data("PWD", (*msh)->env) == NULL))
		set_env("PWD", pwd, msh, 0);
	else if (pwd != NULL)
		modif_env("PWD", pwd, msh);
	if (opwd != NULL && (get_data("OLDPWD", (*msh)->env) == NULL))
		set_env("OLDPWD", opwd, msh, 0);
	else if (opwd != NULL)
		modif_env("OLDPWD", opwd, msh);
	free((*msh)->opwd);
	(*msh)->opwd = ft_strdup(opwd);
	free((*msh)->pwd);
	(*msh)->pwd = ft_strdup(pwd);
}

void			swap_pwdopwd(t_msh **msh)
{
	char		*tmp;

	tmp = ft_strdup((*msh)->opwd);
	free((*msh)->opwd);
	(*msh)->opwd = ft_strdup((*msh)->pwd);
	free((*msh)->pwd);
	(*msh)->pwd = ft_strdup(tmp);
	free(tmp);
}

char			**rm_first(char **cmds)
{
	int			i;
	char		**ret_tab;

	i = 1;
	while (cmds[i] != 0)
		i++;
	if (!(ret_tab = malloc(sizeof(char **) * (i + 1))))
		return (NULL);
	i = 1;
	while (cmds[i] != 0)
	{
		ret_tab[i - 1] = ft_strdup(cmds[i]);
		i++;
	}
	ret_tab[i - 1] = 0;
	return (ret_tab);
}

int				quotenspace(char *str)
{
	int			i;
	int			total;

	i = 0;
	total = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			total++;
		if (str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
			return (1);
		i++;
	}
	if (total == 2)
		return (1);
	return (0);
}

void			adjust_quote(char **str, int dq, int q, int i)
{
	char		*tmp;

	tmp = ft_strdup(*str);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\'')
			q++;
		if (tmp[i] == '\"')
			dq++;
		i++;
	}
	if (dq % 2 != 0)
	{
		ft_strdel(str);
		*str = ft_strjoin(tmp, "\"");
	}
	if (q % 2 != 0)
	{
		ft_strdel(str);
		*str = ft_strjoin(tmp, "\'");
	}
	ft_strdel(&tmp);
}
