/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:03:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/27 22:09:29 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				check_file(char *path, char *file)
{
	struct stat	fs;

	lstat(path, &fs);
	if (access(path, F_OK) != 0)
		return ((ft_printf("cd : No such file or directory: %s\n", file)));
	else if ((fs.st_mode & S_IXUSR) == 0 && (S_ISDIR(fs.st_mode)))
		return ((ft_printf("cd : Permission denied %s\n", file)));
	return (0);
}

int				check_directory(char *path)
{
	struct stat	fs;

	lstat(path, &fs);
	if (access(path, F_OK) != 0)
		return ((ft_printf("cd : No such file or directory: %s\n", path)));
	else if ((fs.st_mode & S_IXUSR) == 0 && (S_ISDIR(fs.st_mode)))
		return ((ft_printf("cd : Permission denied %s\n", path)));
	return (0);
}
