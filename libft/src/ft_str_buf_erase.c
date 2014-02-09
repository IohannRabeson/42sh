/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_erase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:51:37 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/05 18:02:31 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include "ft_memory.h"

t_ui	str_buf_erase(t_str_buf *strbuf, t_ui start, t_ui length)
{
	if (start >= strbuf->size)
		return (0);
	if (start + length >= strbuf->size)
		length = strbuf->size - start;
	if (length == 0)
		return (0);
	ft_memmove(strbuf->buffer + start,
			   strbuf->buffer + start + length,
			   strbuf->size - (start + length));
	strbuf->size -= length;
	return (length);
}
