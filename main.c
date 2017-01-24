
#include "minishell.h"

void		exec_msh(t_msh **msh, char *line, char **cmds)
{
	int		ret;
	int		pid;

	while (42)
	{
		ret = get_next_line(0, &line);
		if (ret && *line != '\n')
		{
//			printf("line is:%s\n", line);
			cmds = ft_strsplit(line, ' ');
			if (select_cmd(cmds[0], *msh) == 1)
				exec_cmd(cmds, msh);
//			else
//			{
//				pid = fork();
//				if (pid == 0)
//					exec_bin(cmds, *msh);
//			}
//			freecmds(&cmds);
		}
		free(line);
//		wait(&pid);
		ft_putstr("\n$>");
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_msh	*msh;
	char	*line;
	char	**cmds;

	line = NULL;
	cmds = NULL;
	init_msh(&msh, envp);
	ft_putstr("$>");
	exec_msh(&msh, line, cmds);
	return (0);
}
