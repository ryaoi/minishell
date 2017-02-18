/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:15:17 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/18 17:28:42 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				fdputc(int c)
{
	write(2, &c, 1);
	return (1);
}

void			clrterm(void)
{
	tputs(tgetstr("cl", NULL), 1, fdputc);
}

int				init_term(t_msh *msh)
{
	char		*term;

	if (!(term = getenv("TERM")))
		term = "xterm-256color";
	if ((tgetent(NULL, term) != 1))
		return (0);
	tcgetattr(0, &msh->term);
	msh->term.c_cc[VMIN] = 1;
	msh->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, 0, &msh->term) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 1, fdputc);
	return (1);
}

int				reset_term(t_msh *msh)
{
	if (tcsetattr(0, 0, &msh->term) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, fdputc);
	return (1);
}
