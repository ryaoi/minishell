/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:36:36 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/30 19:31:20 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exec_msh(t_msh **msh, char *line, char **cmds)
{
	int		ret;
	int		pid;

	while (42)
	{
		ret = read_stdin(&line);
		if (ret)
		{
			cmds = ft_strsplit(line, ' ');
			free(line);
			if (select_cmd(cmds[0], *msh) == 1)
				exec_cmd(cmds, msh);
			else
			{
				pid = fork();
				if (pid == 0)
					exec_bin(cmds, *msh);
				wait(&pid);
			}
			freecmds(cmds);
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
