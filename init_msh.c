
#include "minishell.h"

static void		add_env(t_env **head, char *str)
{
	t_env		*ptr;
	t_env		*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(str);
//	printf("name:%s\n", new->name);
	new->next = NULL;
	if ((*head) == NULL)
	{
		*head = new;
		return ;
	}
	ptr = (*head);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

static void		init_env(t_msh **msh, char **envp)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		add_env(&((*msh)->env), envp[i]);
		i++;
	}
}

static void		init_bin_dir(t_msh **msh, char **envp)
{
	char		*str;

	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	str = ft_strsub(*envp, 5, ft_strlen(*envp));
	(*msh)->bin_dir = ft_strsplit(str, ':');
	ft_strdel(&str);
/*
    int i = 0;
    while ((*msh)->bin_dir[i] != 0)
    {
        printf("bin_dir:%s\n", (*msh)->bin_dir[i]);
        i++;
    }
*/
}

void			init_msh(t_msh **msh, char **envp)
{
	if (!((*msh) = (t_msh *)malloc(sizeof(t_msh))))
		exit(EXIT_FAILURE);
	if (!((*msh)->func = (char **)malloc(sizeof(char *) * 7)))
		exit(EXIT_FAILURE);
	(*msh)->func[0] = ft_strdup("echo");
	(*msh)->func[1] = ft_strdup("cd");
	(*msh)->func[2] = ft_strdup("setenv");
	(*msh)->func[3] = ft_strdup("unsetenv");
	(*msh)->func[4] = ft_strdup("env");
	(*msh)->func[5] = ft_strdup("exit");
	(*msh)->func[6] = 0;
	(*msh)->env = NULL;
	init_env(msh, envp);
	init_bin_dir(msh, envp);
}
