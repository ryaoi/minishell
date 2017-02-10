/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:36:36 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/10 20:34:48 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	intro(void)
{
	ft_putstr(GREEN);
	ft_putstr("------------------\n");
	ft_putstr("|   minishell    |\n");
	ft_putstr("------------------\n");
	ft_putstr(RESET);
}

static void	use_bin(char **cmds, t_msh **msh)
{
	int		pid;

	pid = fork();
	if (pid == 0)
		exec_bin(cmds, *msh);
	wait(&pid);
}

static void	sub_msh(t_msh **msh, char *sep_cmd, char **full_cmd)
{
	char	**cmds;
	int		pid;
	char	*new_cmd;

	if (ft_strchr(sep_cmd, '\'') == NULL)
		new_cmd = envtostr(sep_cmd, 0, msh);
	else
		new_cmd = ft_strdup(sep_cmd);
	cmds = ft_strsplit(new_cmd, ' ');
	if (cmds[0][0] == '\'' || cmds[0][0] == '\"')
		cmds[0] = ft_strsubfree(cmds[0], 1, ft_strlen(cmds[0]) - 2);
	if (select_cmd(cmds[0], *msh) == 1)
	{
		if (ft_strcmp(cmds[0], "exit") == 0)
			exec_exit(cmds, msh, full_cmd);
		else
			exec_cmd(cmds, msh);
	}
	else
		use_bin(cmds, msh);
	freecmds(cmds);
	ft_strdel(&new_cmd);
}

void		exec_msh(t_msh **msh, char *line, char **sep_cmd)
{
	int		ret;
	int		i;

	while (42)
	{
		i = 0;
		ret = read_stdin(&line);
		if (ret)
		{
			sep_cmd = ft_strsplit(line, ';');
			free(line);
			while (sep_cmd[i] != 0)
			{
				sub_msh(msh, sep_cmd[i], sep_cmd);
				i++;
			}
			freecmds(sep_cmd);
		}
		ft_putstr("$>");
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_msh	*msh;

	(void)argc;
	(void)argv;
	init_msh(&msh, envp);
	init_term(msh);
	clrterm();
	intro();
	ft_putstr("$>");
	exec_msh(&msh, NULL, NULL);
	return (0);
}
