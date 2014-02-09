/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit_move_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:52:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 22:07:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"
#include <ft_string.h>

static t_bool	is_word_ch(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || c == '_');
}

void			cursor_next_word(t_textedit *te)
{
	t_cursor	*cursor;
	t_ui		buf_sz;
	char		c;
	t_bool		sp;

	buf_sz = str_buf_size(&te->buffer);
	cursor = &te->cursor;
	sp = false;
	while (cursor->buffer_pos < buf_sz)
	{
		c = str_buf_get_char(&te->buffer, cursor->buffer_pos);
		if (!is_word_ch(c))
			sp = true;
		else if (sp == true)
			break ;
		else
			sp = false;
		cursor_next_char(te);
	}
}

static void		skip_space(t_textedit *te)
{
	t_cursor	*cursor;
	t_ui		buf_sz;
	char		c;

	buf_sz = str_buf_size(&te->buffer);
	cursor = &te->cursor;
	if (cursor->buffer_pos > te->prompt.size)
		cursor_prev_char(te);
	while (cursor->buffer_pos > te->prompt.size)
	{
		if (cursor->buffer_pos < buf_sz)
		{
			c = str_buf_get_char(&te->buffer, cursor->buffer_pos);
			if (is_word_ch(c))
				break ;
		}
		cursor_prev_char(te);
	}
}

void			cursor_prev_word(t_textedit *te)
{
	t_cursor	*cursor;
	t_ui		buf_sz;
	char		c;

	buf_sz = str_buf_size(&te->buffer);
	cursor = &te->cursor;
	skip_space(te);
	while (cursor->buffer_pos > te->prompt.size)
	{
		if (cursor->buffer_pos < buf_sz
			&& cursor->buffer_pos > te->prompt.size + 1)
		{
			c = str_buf_get_char(&te->buffer, cursor->buffer_pos - 1);
			if (!is_word_ch(c))
				break ;
		}
		cursor_prev_char(te);
	}
}
