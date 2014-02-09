/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_rw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 17:09:02 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/28 17:26:48 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include <unistd.h>

t_ui	str_buf_write(t_str_buf const *strbuf, int fd)
{
	if (fd == -1)
		return (0);
	return (write(fd, strbuf->buffer, strbuf->size));
}

t_ui	str_buf_read(t_str_buf *strbuf, int fd)
{
	int		readed;
	char	buffer[1024];
	t_ui	total;

	total = 0;
	while ((readed = read(fd, buffer, 1024)) > 0)
	{
		str_buf_app_strn(strbuf, buffer, readed);
		total += readed;
	}
	return (total);
}
