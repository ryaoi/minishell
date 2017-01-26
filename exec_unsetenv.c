
#include "minishell.h"

void			exec_unsetenv(char **cmds, t_msh **msh)
{
	t_env		*ptr;
	t_env		*prev;

	ptr = (*msh)->env;
	prev = ptr;
	while (ptr != NULL)
	{
		if (ft_strncmp(cmds[1], ptr->name, ft_strlen(cmds[1])) == 0)
		{
			prev->next = ptr->next;
			free(ptr->name);
			free(ptr->data);
			free(ptr);
			return ;
		}
		prev = ptr;
		ptr = ptr->next;
	}
}
