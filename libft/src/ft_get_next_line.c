/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 00:24:29 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/16 14:24:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include "ft_error.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

static void			gnl_buffer_clean(t_gnl *gnl, size_t start)
{
	size_t	i;
	size_t	max_i;

	i = 0;
	max_i = gnl->buffer_size - start;
	while (i < max_i)
	{
		gnl->buffer[i] = gnl->buffer[i + start];
		++i;
	}
	gnl->buffer_size = max_i;
}

static int			gnl_buffer_contains(t_gnl *gnl,
										size_t *pos,
										char c,
										char **line)
{
	size_t	i;
	size_t	line_size;

	i = 0;
	while (i < gnl->buffer_size)
	{
		line_size = i;
		if (gnl->buffer[i] == c)
		{
			*pos = line_size;
			if (line_size == 0)
				*line = ft_strdup("");
			else
				*line = ft_strndup(gnl->buffer, line_size);
			if (gnl->buffer_size > 0 && line_size < gnl->buffer_size - 1)
				gnl_buffer_clean(gnl, line_size + 1);
			else
				gnl->buffer_size = 0;
			return (1);
		}
		++i;
	}
	return (0);
}

static void			gnl_buffer_destroy(t_gnl *gnl)
{
	if (gnl->buffer)
	{
		free(gnl->buffer);
		gnl->buffer = NULL;
		gnl->buffer_capacity = 0;
		gnl->buffer_size = 0;
	}
}

int					get_next_line(t_gnl *gnl, char **line, int fd)
{
	int			read_max;
	int			readed;
	size_t		line_size;

	line_size = 0;
	if (gnl->buffer == NULL && gnl_buffer_reserve(gnl, 1) == 0)
		return (-1);
	if (gnl->buffer_size == gnl->buffer_capacity
		&& gnl_buffer_reserve(gnl, gnl->buffer_capacity * 2) == 0)
		return (-1);
	if (gnl_buffer_contains(gnl, &line_size, '\n', line))
		return (1);
	read_max = gnl->buffer_capacity - gnl->buffer_size;
	while ((readed = read(fd, gnl->buffer + gnl->buffer_size, read_max)) > 0)
	{
		gnl->buffer_size += readed;
		if (gnl_buffer_contains(gnl, &line_size, '\n', line))
			return (1);
		if (gnl->buffer_size == gnl->buffer_capacity
			&& gnl_buffer_reserve(gnl, gnl->buffer_capacity * 2) == 0)
			return (-1);
	}
	gnl_buffer_destroy(gnl);
	return (0);
}
