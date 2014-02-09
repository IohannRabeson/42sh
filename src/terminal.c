/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:20:23 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 22:06:22 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void			terminal_init(void)
{
	struct termios	termios;
	char 			*terminal_name;
	
	terminal_name = getenv("TERM");
	if (terminal_name == NULL || tgetent(NULL, terminal_name) < 0)
		return ;
	if (tcgetattr(0, &termios) == -1)
		return ;
	termios.c_lflag &= ~(ICANON | ECHO);
	termios.c_cc[VMIN] = 1;
	termios.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &termios);
}

void			terminal_destroy(void)
{
	struct termios	termios;

	if (tcgetattr(0, &termios) == -1)
		return ;
	termios.c_lflag |= (ECHO | ICANON);
	tcsetattr(0, TCSADRAIN, &termios);
}

int				terminal_out_fd(void)
{
	static int	fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY | O_APPEND);
	return (fd);
}

void			terminal_putstr(char const *str)
{
	while (str && *str)
		terminal_putchar(*(str++));
}
