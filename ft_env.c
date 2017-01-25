
#include "minishell.h"

void		modif_env(char *name, char *new_data, t_msh **msh)
{
	t_env	*ptr;

	ptr = (*msh)->env;
	while (ptr != NULL)
	{
		if (ft_strcmp(ptr->name, name) == 0)
		{
			free(ptr->data);
			ptr->data = ft_strdup(new_data);
			return ;
		}
		ptr = ptr->next;
	}
}
