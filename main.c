
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
//			printf("cmds[0] is:%s and ft_strlenis:%zu\n", cmds[0], ft_strlen(cmds[0]));
			if (select_cmd(cmds[0], *msh) == 1)
				exec_cmd(cmds, msh);
//			else
//			{
//				pid = fork();
//				if (pid == 0)
//					exec_bin(cmds, *msh);
//			}
			freecmds(cmds);
		}
//		wait(&pid);
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
	init_msh(&msh, envp);
	ft_putstr("$>");
	exec_msh(&msh, line, cmds);
	return (0);
}
