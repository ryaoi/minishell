
#include "minishell.h"

static void		env_error(char *str)
{
	ft_putstr("env: ");
	ft_putstr(str);
	ft_putendl(": No such file or directory");
}

void			exec_env(char **cmds,t_msh *msh)
{
	t_env		*ptr;

	if (cmds[1] != NULL)
		env_error(cmds[1]);
	else
	{
		ptr = msh->env;
		while (ptr != NULL)
		{
			ft_putstr(ptr->name);
			ft_putchar('\n');
			ptr = ptr->next;
		}
	}
}
