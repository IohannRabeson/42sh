/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 00:23:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 03:44:05 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define GNL_INITIAL_SIZE	16
# include <stdlib.h>

typedef struct	s_gnl
{
	char		*buffer;
	size_t		buffer_capacity;
	size_t		buffer_size;
}				t_gnl;

void	gnl_init(t_gnl *gnl);
void	gnl_destroy(t_gnl *gnl);
int		get_next_line(t_gnl *gnl, char **line, int fd);

#endif
