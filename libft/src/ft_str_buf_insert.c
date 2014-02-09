/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:22:14 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:50:46 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include <ft_memory.h>
#include <ft_string.h>
#include <ft_minmax.h>

void	str_buf_grow(t_str_buf *strbuf, t_ui to_add)
{
	t_ui	new_cap;

	if (to_add == 0)
		return ;
	new_cap = strbuf->capacity;
	while (strbuf->size + to_add >= new_cap)
		new_cap *= 2;
	str_buf_reserve(strbuf, new_cap);
}

void	str_buf_right(t_str_buf *strbuf, t_ui start, t_ui offset)
{
	if (start >= strbuf->size)
		return ;
	ft_memmove(strbuf->buffer + start + offset,
				strbuf->buffer + start,
				strbuf->size - start);
}

void	str_buf_insert_char(t_str_buf *strbuf, t_ui pos, char c)
{
	if (strbuf->size > 0 && pos < strbuf->size)
	{
		str_buf_right(strbuf, pos, 1);
		strbuf->buffer[pos] = c;
		strbuf->size += 1;
	}
	else
	{
		str_buf_app_char(strbuf, c);
	}
}

void	str_buf_insert_str(t_str_buf *strbuf, t_ui pos, char const *str)
{
	t_ui	str_size;

	if (str == NULL)
		return ;
	str_size = ft_strlen(str);
	if (strbuf->size > 0 && pos < strbuf->size)
	{
		str_buf_right(strbuf, pos, str_size);
		ft_memcpy(strbuf->buffer + pos, str, str_size);
		strbuf->size += str_size;
	}
	else
	{
		str_buf_app_str(strbuf, str);
	}
}

void	str_buf_insert_strn(t_str_buf *strbuf,
							t_ui pos,
							char const *str, t_ui n)
{
	t_ui	str_size;

	if (str == NULL)
		return ;
	str_size = ft_min_uint(ft_strlen(str), n);
	if (strbuf->size > 0 && pos < strbuf->size)
	{
		str_buf_right(strbuf, pos, str_size);
		ft_memcpy(strbuf->buffer + pos, str, str_size);
		strbuf->size = str_size;
	}
	else
	{
		str_buf_app_strn(strbuf, str, n);
	}
}
