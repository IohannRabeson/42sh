/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 23:34:15 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:50:18 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include "ft_error.h"
#include <stdlib.h>

char	str_buf_get_char(t_str_buf const *strbuf, t_ui pos)
{
	if (pos >= strbuf->size)
		exit_errorm("str_buf_get_char", "pos out of bound", 1, NULL);
	return (strbuf->buffer[pos]);
}

char	str_buf_get_last_char(t_str_buf const *strbuf)
{
	if (strbuf->size == 0)
		exit_errorm("str_buf_get_last_char", "empty buffer", 1, NULL);
	return (strbuf->buffer[strbuf->size - 1]);
}
