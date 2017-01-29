
#include "minishell.h"

static void		printall_env(t_msh *msh)
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

static int		env_error(char *str)
{
	struct stat	fs;

	lstat(str, &fs);
	if (access(str, F_OK) != 0)
		return ((ft_printf("env : %s: No such file or directory\n", str)));
	else
		return ((ft_printf("env : %s: Permission denied\n", str)));
	ft_strdel(&str);
}

void			print_doubledot(char *str, t_msh *msh, int i, int j)
{
	char		*name;

	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			i++;
			j = i;
			while ((str[j] >= 'A' && str[j] <= 'Z') && str[j] != '\0')
				j++;
			j -= i;
			name = ft_strsub(str, i, j);
			if (search_env(name, msh->env) == 1)
				print_env(name, msh->env);
			else
				ft_putstr(name);
			ft_strdel(&name);
			while ((str[i] >= 'A' && str[i] <= 'Z') && str[i] != '\0')
				i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	ft_strdel(&str);
}

static void		modify_cmds(char *str, t_msh *msh)
{
	t_env		*ptr;
	char		*name;

	name = ft_strsub(str, 1, ft_strlen(str));
	if (search_env(name, msh->env) == 0)
	{
		printall_env(msh);
		return ;
	}
	else
	{
		ptr = msh->env;
		while (ptr != NULL)
		{
			if (ft_strcmp(name, ptr->name) == 0)
				env_error(ptr->data);
			ptr = ptr->next;
		}
	}
}

void			exec_env(char **cmds,t_msh *msh)
{
	char		*str;

	if (cmds[1] == NULL)
		printall_env(msh);
	else if (cmds[1][0] == '\'')
	{
		str = inspectquote(cmds, '\'');
		env_error(str);
	}
	else if (cmds[1][0] == '\"')
	{
		str = inspectquote(cmds, '\"');
		printf("str is:%s\n", str);
		if (ft_strchr(str, '$') == NULL)
			env_error(str);
		else
		{
			if (search_env(&(str[1]), msh->env) == 1)
				env_error(get_data(&(str[1]), msh->env));
			else
			{
				ft_putstr("env: ");
				print_doubledot(str, msh, 0, 0);
				ft_putendl(": No such file or directory");
			}
		}
	}
	else
		modify_cmds(cmds[1], msh);
}
