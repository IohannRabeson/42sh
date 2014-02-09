/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 16:37:47 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 18:56:38 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"
#include <ft_string.h>

void	cursor_next_char(t_textedit *te)
{
	t_cursor	*cursor;

	cursor = &te->cursor;
	if (cursor->buffer_pos + 1 > str_buf_size(&te->buffer))
		return ;
	cursor->buffer_pos += 1;
	te->modified = true;
}

void	cursor_prev_char(t_textedit *te)
{
	t_cursor	*cursor;

	cursor = &te->cursor;
	if (cursor->buffer_pos <= te->prompt.size)
		return ;
	cursor->buffer_pos -= 1;
	te->modified = true;
}
