/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:54:26 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:09:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include "ft_error.h"
#include <stdlib.h>

void	str_buf_init(t_str_buf *strbuf)
{
	strbuf->buffer = NULL;
	strbuf->size = 0;
	strbuf->capacity = 0;
	str_buf_reserve(strbuf, 16);
}

void	str_buf_destroy(t_str_buf *strbuf)
{
	if (strbuf == NULL)
		return ;
	if (strbuf->buffer)
	{
		free(strbuf->buffer);
		strbuf->buffer = NULL;
	}
	strbuf->size = 0;
	strbuf->capacity = 0;
}

void	str_buf_reserve(t_str_buf *strbuf, t_ui new_cap)
{
	t_ui	i;
	t_ui	new_size;
	char	*new_buf;

	if (new_cap == strbuf->capacity)
		return ;
	new_buf = (char *)malloc(sizeof(*new_buf) * new_cap);
	if (new_buf == NULL)
		exit_errorc("str_buf_reserve", ERRC_NOT_ENOUGH_MEMORY, 1, NULL);
	i = 0;
	new_size = (new_cap < strbuf->size) ? new_cap : strbuf->size;
	while (i < new_size)
	{
		new_buf[i] = strbuf->buffer[i];
		++i;
	}
	if (strbuf->buffer)
		free(strbuf->buffer);
	strbuf->buffer = new_buf;
	strbuf->size = new_size;
	strbuf->capacity = new_cap;
}

void	str_buf_clear(t_str_buf *strbuf)
{
	strbuf->size = 0;
	if (strbuf->capacity > 0 && strbuf->buffer)
		strbuf->buffer[0] = '\0';
}
