/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:26:44 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 18:10:33 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"

void	cursor_backspace(t_textedit *te)
{
	if (te->cursor.buffer_pos <= te->prompt.size)
		return ;
	cursor_prev_char(te);
	if (str_buf_get_char(&te->buffer, te->cursor.buffer_pos) == '\r')
	{
		str_buf_erase(&te->buffer, te->cursor.buffer_pos, 1);
		cursor_prev_char(te);
	}
	str_buf_erase(&te->buffer, te->cursor.buffer_pos, 1);
	te->modified = true;
}

void	cursor_suppr(t_textedit *te)
{
	if (te->cursor.buffer_pos == str_buf_size(&te->buffer)
		|| str_buf_size(&te->buffer) == 0)
		return ;
	str_buf_erase(&te->buffer, te->cursor.buffer_pos, 1);
	te->modified = true;
}
