/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 22:08:06 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/19 05:08:21 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"
#include "terminal.h"
#include "app.h"
#include <ft_memory.h>
#include <ft_string.h>
#include <stdlib.h>

void	textedit_init(t_textedit *te, char const *prompt, t_val_func val_func)
{
	ft_bzero(te, sizeof(*te));
	str_buf_init(&te->buffer);
	te->prompt.str = ft_strdup(prompt);
	te->prompt.size = ft_strlen(prompt);
	te->width = terminal_width();
	te->height = terminal_height();
	te->scroll = 0;
	te->first = true;
	te->val_func = val_func;
	textedit_reset(te);
}

void	textedit_destroy(t_textedit *te)
{
	terminal_putchar('\n');
	str_buf_destroy(&te->buffer);
	if (te->prompt.str)
		free(te->prompt.str);
	ft_bzero(te, sizeof(*te));
}

void	textedit_reset(t_textedit *te)
{
	str_buf_clear(&te->buffer);
	if (te->first)
		te->first = false;
	terminal_exec("sc");
	te->cursor.buffer_pos = 0;
	te->cursor.col = 0;
	te->cursor.row += 1;
	te->scroll = 0;
	cursor_insert_str(te, te->prompt.str);
	te->modified = true;
	textedit_display(te);
}

void	textedit_validate(t_textedit *te)
{
	char	*str;

	if (textedit_multiline(te))
	{
		cursor_insert(te, '\r');
		te->modified = true;
	}
	else if (str_buf_size(&te->buffer) > te->prompt.size)
	{
		str_buf_erase(&te->buffer, 0, te->prompt.size);
		str_buf_replace_all(&te->buffer, "\r", "");
		str = str_buf_get(&te->buffer);
		if (str && ft_strlen(str) > 0 && te->val_func)
			te->val_func(str);
		else
			terminal_putchar('\n');
		if (str)
		{
			free(str);
		}
		if (app_instance()->run)
			textedit_reset(te);
	}
}
