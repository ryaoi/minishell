
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

void		set_env(char *name, char *data, t_msh **msh)
{
	t_env	*ptr;
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(name);
	new->data = ft_strdup(data);
	new->next = NULL;
	if ((*msh)->env == NULL)
		(*msh)->env = new;
	else
	{
		ptr = (*msh)->env;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}
