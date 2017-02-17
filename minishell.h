/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:56:51 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/17 05:54:36 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>

# define GREEN	"\x1b[32m"
# define RESET	"\x1b[0m"

typedef	struct		s_env
{
	char			*name;
	char			*data;
	int				modif;
	struct s_env	*next;
}					t_env;

typedef struct		s_msh
{
	t_env			*env;
	struct termios	term;
	char			**func;
	char			**bin_dir;
	char			*pwd;
	char			*home;
	char			*opwd;
	int				process;
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
void				set_env(char *name, char *data, t_msh **msh, int modif);
char				*get_data(char *name, t_env *env);
char				*get_str_env(char *str, int size, t_msh **msh);
int					check_env_name(char *str, int i, t_env *env);
int					check_file(char *path, char *file);
int					check_directory(char *path);
void				replace_envdata(char *name, char *data, t_msh **msh,
					int modif);
void				print_env(char *str, t_env *env);
char				*inspectquote(char **cmds, char c);
char				*inspectquotetwo(char **cmds, char c);
char				*inspectquotezero(char **cmds, char c);
void				print_doubledot(char *str, t_msh *msh, int i, int j);
void				exec_bin(char **cmds, t_msh *msh);
void				env_string_err(char *str, t_msh *msh);
int					env_error(char *str);
char				*envtostr(char *str, int i, t_msh **msh);
char				*straddonefree(char *str, char c, int i);
int					fdputc(int c);
int					init_term(t_msh *msh);
int					reset_term(t_msh *msh);
void				handle_signal(t_msh *msh);
void				clrterm(void);
void				print_echo(char **cmds, t_msh *msh);
void				check_single(char **str);
void				check_space(char **cmds);
int					stronly(char *str, char c);
void				check_linked(char **str, t_msh *msh);
int					check_quote(char *str);
void				env_pwdopwd(char *pwd, char *opwd, t_msh **msh);
void				swap_pwdopwd(t_msh **msh);
char				**rm_first(char **cmds);
void				use_bin(char **cmds, t_msh **msh);

#endif
