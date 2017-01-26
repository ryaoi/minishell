
#include "minishell.h"

static int		all_cap(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int		check_cmds(char **cmds)
{
	int		i;

	i = 0;
	while (cmds[i])
		i++;
	if (i < 2)
		return (ft_printf("Missing the name of the variable to set and the value of the variable\n"));
	else if (i < 3)
		return (ft_printf("Missing the value of the variable\n"));
	else if (all_cap(cmds[1]))
		return (ft_printf("The name of the variable shoud be capitalized\n"));
	return (0);
}

static char		*replace_env(char *str, t_msh **msh)
{
	char		*result;

}

void			exec_setenv(char **cmds, t_msh **msh)
{
	char		*data;

	if (check_cmds(cmds) > 0)
		return ;
	if (cmds[2][0] == '\'')
		data = ft_strsub(cmds[2], 1, ft_strlen(cmds[2]));
	else if (cmds[2][0] == '\"' && ft_strchr(cmds[2], '$') != NULL)
		data = replace_env(cmds[2], t_msh **msh);
	set_env(cmds[1], cmds[2], msh);
}
