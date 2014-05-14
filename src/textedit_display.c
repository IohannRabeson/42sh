/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 14:42:56 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:39:21 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"
#include "terminal.h"
#include <ft_memory.h>

static void	repos_cursor_imp(t_textedit const *te)
{
	t_ui	max;
	t_ui	col;
	t_ui	row;
	t_ui	i;

	col = 0;
	row = 0;
	max = te->cursor.buffer_pos;
	i = 0;
	while (i < max)
	{
		if (col >= te->width - 1 || str_buf_get_char(&te->buffer, i) == '\r')
		{
			col = 0;
			row += 1;
			terminal_exec("cr");
			terminal_exec("do");
		}
		else
			terminal_exec("nd");
		++i;
		++col;
	}
}

static void	repos_cursor(t_textedit const *te)
{
	t_ui	i;

	terminal_exec("rc");
	i = 0;
	while (i < te->scroll)
	{
		terminal_exec("up");
		++i;
	}
	repos_cursor_imp(te);
}

void		textedit_display(t_textedit *te)
{
	t_str_buf	clone;
	t_ui		i;

	if (te->modified == false)
		return ;
	str_buf_init(&clone);
	str_buf_clone(&clone, &te->buffer);
	str_buf_replace_all(&clone, "\r", "\n");
	terminal_exec("rc");
	i = 0;
	while (i < te->scroll)
	{
		terminal_exec("up");
		++i;
	}
	terminal_exec("cd");
	str_buf_write(&clone, terminal_out_fd());
	te->modified = false;
	repos_cursor(te);
	str_buf_destroy(&clone);
}
