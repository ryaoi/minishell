
#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>

typedef	struct		s_env
{
	char			*name;
	struct s_env	*next;
}					t_env;

typedef struct		s_msh
{
	t_env			*env;
	char			**func;
	char			**bin_dir;
}					t_msh;

void				init_msh(t_msh **msh, char **envp);
void				exec_echo(char **cmds, t_msh *msh);
int					search_env(char *str, t_env *env);
int					select_cmd(char *line, t_msh *msh);
void				exec_cmd(char **cmds, t_msh **msh);
void				exec_msh(t_msh **msh, char *line, char **cmds);
void				exec_env(char **cmds, t_msh *msh);

#endif
