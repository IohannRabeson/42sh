/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:33:27 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:59:32 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <unistd.h>
#include <term.h>
#include <ft_error.h>
#include <ft_print.h>

int			terminal_putchar(int c)
{
	int const	happy_compiler = write (terminal_out_fd(), &c, 1);

	return (1);
	(void)happy_compiler;
}

void		terminal_exec(char *cmd)
{
	char	*term_cmd;

	if (cmd)
	{
		term_cmd = tgetstr(cmd, NULL);
		if (term_cmd)
			tputs(term_cmd, 0, terminal_putchar);
		else
		{
			ft_putstr_fd("ft_sh: ", STDERR_FILENO);
			ft_putstr_fd(cmd, STDERR_FILENO);
			ft_putendl_fd(": unknow termcap", STDERR_FILENO);
		}
	}
}

void		terminal_goto(t_ui x, t_ui y)
{
	char	*term_cmd;
	char	*cm_cmd;

	cm_cmd = tgetstr("cm", NULL);
	if (cm_cmd == false)
		return ;
	term_cmd = tgoto(cm_cmd, x, y);
	if (term_cmd)
		tputs(term_cmd, 0, terminal_putchar);
	else
	{
		ft_putstr_fd("ft_sh: ", STDERR_FILENO);
		ft_putstr_fd("tgoto failed: ", STDERR_FILENO);
		ft_putendl_fd(term_cmd, STDERR_FILENO);
	}
}

void		terminal_clear(void)
{
	terminal_exec("cl");
}
