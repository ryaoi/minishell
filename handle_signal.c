/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:22:51 by ryaoi             #+#    #+#             */
/*   Updated: 2017/02/10 17:37:25 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_msh			*g_msh;

static t_msh	*mshtoglb(t_msh *msh)
{
	return (msh);
}

static void		ft_sigint(int sig)
{
	(void)sig;
	reset_term(g_msh);
	freemsh(&g_msh);
	free(g_msh);
	exit(0);
}

static void		ft_sigcont(int sig)
{
	(void)sig;
	g_msh->term.c_cc[VMIN] = 1;
	g_msh->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(g_msh->term));
	tputs(tgetstr("ti", NULL), 1, fdputc);
}

static void		ft_sigstop(int sig)
{
	(void)sig;
	clrterm();
	tcsetattr(0, 0, &(g_msh->term));
	tputs(tgetstr("te", NULL), 1, fdputc);
}

void			handle_signal(t_msh *msh)
{
	g_msh = mshtoglb(msh);
	signal(SIGCONT, ft_sigcont);
	signal(SIGSTOP, ft_sigstop);
	signal(SIGINT, ft_sigint);
}
