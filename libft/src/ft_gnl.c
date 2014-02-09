/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 03:44:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 13:34:36 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include "ft_memory.h"

void	gnl_init(t_gnl *gnl)
{
	gnl->buffer = NULL;
	gnl->buffer_size = 0;
	gnl->buffer_capacity = 0;
}

void	gnl_destroy(t_gnl *gnl)
{
	if (gnl->buffer)
	{
		free(gnl->buffer);
		gnl->buffer = NULL;
		gnl->buffer_size = 0;
		gnl->buffer_capacity = 0;
	}
}

int		gnl_buffer_reserve(t_gnl *gnl, size_t new_cap)
{
	char	*new_buf;
	size_t	i;
	size_t	max_i;

	if (new_cap == gnl->buffer_capacity)
		return (1);
	new_buf = (char *)malloc(sizeof(*new_buf) * new_cap);
	ft_bzero(new_buf, sizeof(*new_buf) * new_cap);
	if (new_buf == NULL)
		return (0);
	i = 0;
	max_i = (new_cap < gnl->buffer_size) ? new_cap : gnl->buffer_size;
	while (i < max_i)
	{
		new_buf[i] = gnl->buffer[i];
		++i;
	}
	if (gnl->buffer)
		free(gnl->buffer);
	gnl->buffer = new_buf;
	gnl->buffer_capacity = new_cap;
	gnl->buffer_size = max_i;
	return (1);
}
