/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:56:51 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/30 20:04:23 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

typedef	struct		s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}					t_env;

typedef struct		s_msh
{
	t_env			*env;
	char			**func;
	char			**bin_dir;
	char			*pwd;
	char			*home;
}					t_msh;

void				init_msh(t_msh **msh, char **envp);
void				exec_echo(char **cmds, t_msh *msh);
int					search_env(char *str, t_env *env);
int					select_cmd(char *line, t_msh *msh);
void				exec_cmd(char **cmds, t_msh **msh);
void				exec_msh(t_msh **msh, char *line, char **cmds);
void				exec_env(char **cmds, t_msh *msh);
void				exec_unsetenv(char **cmds, t_msh **msh);
void				exec_setenv(char **cmds, t_msh **msh);
void				exec_cd(char **cmds, t_msh **msh);
void				exec_exit(char **cmds, t_msh **msh, char **full_cmd);
int					read_stdin(char **line);
void				freemsh(t_msh **msh);
void				freeenv(t_env **env);
void				freecmds(char **cmds);
void				modif_env(char *name, char *new_ddata, t_msh **msh);
void				set_env(char *name, char *data, t_msh **msh);
char				*get_data(char *name, t_env *env);
char				*get_str_env(char *str, int size, t_msh **msh);
int					check_env_name(char *str, int i, t_env *env);
int					check_file(char *path, char *file);
int					check_directory(char *path);
void				replace_envdata(char *name, char *data, t_msh **msh);
void				print_env(char *str, t_env *env);
char				*inspectquote(char **cmds, char c);
char				*inspectquotetwo(char **cmds, char c);
void				print_doubledot(char *str, t_msh *msh, int i, int j);
void				exec_bin(char **cmds, t_msh *msh);
void				env_string_err(char *str, t_msh *msh);
int					env_error(char *str);

#endif
