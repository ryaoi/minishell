
#include "minishell.h"

static void		print_env(char *str, t_env *env)
{
	t_env		*ptr;

	ptr = env;
	while (ptr != NULL)
	{
        if (ft_strcmp(str, ptr->name) == 0)
		{
            ft_putstr(ptr->data);
			return ;
		}
        ptr = ptr->next;
	}	
}

int				search_env(char *str, t_env *env)
{
	t_env		*ptr;

	ptr = env;
	while (ptr != NULL)
	{
		if (ft_strcmp(str, ptr->name) == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static int		ft_putenv(char *str, t_msh *msh, int j)
{
	int			i;
	char		*env;

	i = j + 1;
	while (ft_isalpha(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '\"')
		i--;
	env = ft_strsub(str, j + 1, i - 1);
	if (search_env(env, msh->env) == 1)
		print_env(env, msh->env);
	ft_strdel(&env);
    if (str[i + 1] == '\"')
        i++;
	return (i);
}

void			sub_echo(char **cmds, int *i, int *j, int *max)
{
	int			k;

	k = 1;
	if (cmds[*i][0] == '\'')
	{
		while (cmds[*i][k] != '\0')
		{
			if ((cmds[*i][k] == '\"' && cmds[*i][k - 1] == '\\')
				|| (cmds[*i][k] == '\'' && cmds[*i][k - 1] == '\\'))
				ft_putchar(cmds[*i][k]);
			else if (cmds[*i][k] != '\\' && cmds[*i][k] != '\'')
				ft_putchar(cmds[*i][k]);
			k++;
		}
	}
	else if (cmds[*i][0] == '\"')
	{
		*j = 1;
		*max = ft_strlen(cmds[*i]) - 1;
	}
	else
	{
		*j = 0;
		*max = ft_strlen(cmds[*i]);
	}
}

void			exec_echo(char **cmds, t_msh *msh)
{
	int			i;
	int			j;
	int			max;

	i = 1;
	while (cmds[i])
	{
		sub_echo(cmds, &i, &j, &max);
		while (j < max && cmds[i][0] != '\'')
		{
			if (cmds[i][j] == '$')
				j = ft_putenv(cmds[i], msh, j) - 1;
			else if (cmds[i][j] != '\"')
				ft_putchar(cmds[i][j]);
			j++;
		}	
		i++;
		if (cmds[i] != 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
