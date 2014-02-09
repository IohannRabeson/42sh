/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_app.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:06:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/29 18:16:10 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include "ft_string.h"
#include "ft_minmax.h"

void	str_buf_app_char(t_str_buf *strbuf, char c)
{
	if (strbuf->capacity == 0)
		str_buf_reserve(strbuf, 16);
	if (strbuf->size + 1 >= strbuf->capacity)
		str_buf_reserve(strbuf, strbuf->capacity * 2);
	strbuf->buffer[strbuf->size++] = c;
}

void	str_buf_app_str(t_str_buf *strbuf, char const *str)
{
	t_ui const	str_len = ft_strlen(str);
	t_ui		new_cap;

	if (strbuf->capacity == 0)
		str_buf_reserve(strbuf, 16);
	new_cap = strbuf->capacity;
	while (strbuf->size + str_len >= new_cap)
		new_cap *= 2;
	str_buf_reserve(strbuf, new_cap);
	ft_strcpy(strbuf->buffer + strbuf->size, str);
	strbuf->size += str_len;
}

void	str_buf_app_strn(t_str_buf *strbuf, char const *str, t_ui n)
{
	t_ui		new_cap;

	if (strbuf->capacity == 0)
		str_buf_reserve(strbuf, 16);
	new_cap = strbuf->capacity;
	while (strbuf->size + n >= new_cap)
		new_cap *= 2;
	str_buf_reserve(strbuf, new_cap);
	ft_strncpy(strbuf->buffer + strbuf->size, str, n);
	strbuf->size += n;
}
