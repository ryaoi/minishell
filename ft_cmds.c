
#include "minishell.h"

int			select_cmd(char *line, t_msh *msh)
{
	if (ft_strcmp(line, (msh->func)[0]) == 0 || ft_strcmp(line, (msh->func)[1]) == 0
		|| ft_strcmp(line, msh->func[2]) == 0 || ft_strcmp(line, msh->func[3]) == 0
		|| ft_strcmp(line, msh->func[4]) == 0 || ft_strcmp(line, msh->func[5]) == 0)
		return (1);
	return (0);
}

void		exec_cmd(char **cmds, t_msh **msh)
{
	if (ft_strcmp(cmds[0], (*msh)->func[0]) == 0)
		exec_echo(cmds, *msh);
    else if (ft_strcmp(cmds[0], (*msh)->func[4]) == 0)
        exec_env(cmds, *msh);
/*
	else if (ft_strcmp(cmds[0], msh->func[1]) == 0)
		exec_cd(cmds, *msh);
    else if (ft_strcmp(cmds[0], msh->func[2]) == 0)
        exec_setenv(cmds, msh);
    else if (ft_strcmp(cmds[0], msh->func[3]) == 0)
        exec_unsetenv(cmds, msh);
    else if (ft_strcmp(cmds[0], msh->func[5]) == 0)
        exec_exit(cmds);
*/
}
