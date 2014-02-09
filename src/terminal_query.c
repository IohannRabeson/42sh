/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_query.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:38:56 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 01:58:40 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <sys/ioctl.h>
#include <stdlib.h>
#include <ft_error.h>

t_ui	terminal_width(void)
{
	struct winsize terminal_size;

	if (ioctl(0, TIOCGWINSZ, &terminal_size) == -1)
		exit_errorm("terminal_update_size",
					"failed to get size", 1, terminal_destroy);
	return (terminal_size.ws_col);
}

t_ui	terminal_height(void)
{
	struct winsize terminal_size;

	if (ioctl(0, TIOCGWINSZ, &terminal_size) == -1)
		exit_errorm("terminal_update_size",
					"failed to get size", 1, terminal_destroy);
	return (terminal_size.ws_row);
}
