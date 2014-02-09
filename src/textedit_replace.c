/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 16:48:32 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 17:51:33 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"

void	textedit_replace_text(t_textedit *te, char const *str)
{
	t_ui	len;
	t_ui	new_size;

	if (str_buf_size(&te->buffer) == 0)
		return ;
	len = str_buf_size(&te->buffer) - te->prompt.size;
	str_buf_erase(&te->buffer, te->prompt.size, len);
	str_buf_insert_str(&te->buffer, te->prompt.size, str);
	new_size = str_buf_size(&te->buffer);
	te->cursor.buffer_pos = new_size;
	te->modified = true;
}
