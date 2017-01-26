
#include "minishell.h"

static void		print_env(t_msh *msh)
{
	t_env		*ptr;

	ptr = msh->env;
	while (ptr != NULL)
	{
		ft_putstr(ptr->name);
		ft_putchar('=');
		ft_putstr(ptr->data);
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

static void		env_error(char *str)
{
	ft_putstr("env: ");
	ft_putstr(str);
	ft_putendl(": No such file or directory");
}

static void		modify_cmds(char *str, t_msh *msh)
{
	t_env		*ptr;
	char		*name;

	name = ft_strsub(str, 1, ft_strlen(str));
	if (search_env(name, msh->env) == 0)
	{
		print_env(msh);
		return ;
	}
	else
	{
		ptr = msh->env;
		while (ptr != NULL)
		{
			if (ft_strcmp(name, ptr->name) == 0)
				env_error(ptr->name);
			ptr = ptr->next;
		}
	}
}

void			exec_env(char **cmds,t_msh *msh)
{
	if (cmds[1] == NULL)
		print_env(msh);
	else if (ft_strchr(cmds[1], '$') == NULL)
		env_error(cmds[1]);
	else
		modify_cmds(cmds[1], msh);
}
