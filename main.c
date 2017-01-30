/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:36:36 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/30 20:06:30 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sub_msh(t_msh **msh, char *sep_cmd, char **full_cmd)
{
	char	**cmds;
	int		pid;

	cmds = ft_strsplit(sep_cmd, ' ');
	if (select_cmd(cmds[0], *msh) == 1)
	{
		if (ft_strcmp(cmds[0], "exit") == 0)
			exec_exit(cmds, msh, full_cmd);
		else
			exec_cmd(cmds, msh);
	}
	else
	{
		pid = fork();
		if (pid == 0)
			exec_bin(cmds, *msh);
		wait(&pid);
	}
	freecmds(cmds);
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
	char	*line;
	char	**cmds;

	line = NULL;
	cmds = NULL;
	(void)argc;
	(void)argv;
	init_msh(&msh, envp);
	ft_putstr("$>");
	exec_msh(&msh, line, cmds);
	return (0);
}
