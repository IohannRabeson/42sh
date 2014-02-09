/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:04:46 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/05 17:49:57 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include <ft_string.h>

char	*str_buf_get(t_str_buf const *strbuf)
{
	if (strbuf == NULL)
		return (NULL);
	else
		return (ft_strndup(strbuf->buffer, strbuf->size));
}

char	*str_buf_getsub(t_str_buf const *strbuf, t_ui start, t_ui length)
{
	if (start >= strbuf->size)
		return (ft_strdup(""));
	if (start + length > strbuf->size)
		length = strbuf->size - start;
	return (ft_strndup(strbuf->buffer + start, length));
}

t_ui	str_buf_size(t_str_buf const *strbuf)
{
	return (strbuf->size);
}
