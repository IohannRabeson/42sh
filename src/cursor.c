/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 22:12:50 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 17:35:05 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"
#include "terminal.h"
#include <ft_minmax.h>
#include <ft_string.h>

void	cursor_advance(t_textedit *te, t_ui n)
{
	t_cursor	*cursor;
	t_ui		i;

	if (n == 0)
		return ;
	cursor = &te->cursor;
	if (cursor->buffer_pos + n >= str_buf_size(&te->buffer))
		n = str_buf_size(&te->buffer) - cursor->buffer_pos;
	i = 0;
	while (i < n)
	{
		terminal_exec("nd");
		++i;
	}
	cursor->buffer_pos += n;
}

void	cursor_back(t_textedit *te, t_ui n)
{
	t_cursor	*cursor;
	t_ui		i;

	if (n == 0)
		return ;
	cursor = &te->cursor;
	i = 0;
	while (i < n)
	{
		terminal_exec("le");
		++i;
	}
	cursor->buffer_pos -= n;
}

void	cursor_insert(t_textedit *te, char c)
{
	str_buf_insert_char(&te->buffer, te->cursor.buffer_pos, c);
	if (c == '\r')
	{
		te->cursor.col = 0;
		te->cursor.row += 1;
		te->cursor.buffer_pos += 1;
		if (te->cursor.row >= te->height)
		{	
			++te->scroll;
		}
	}
	else
	{
		cursor_advance(te, 1);
	}
	te->modified = true;
}

void	cursor_insert_str(t_textedit *te, char const *str)
{
	str_buf_insert_str(&te->buffer, te->cursor.buffer_pos, str);
	cursor_advance(te, ft_strlen(str));
	te->modified = true;
}
