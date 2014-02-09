/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 04:11:14 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 23:00:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_minmax.h"
#include <stdlib.h>

void		*ft_realloc(void *ptr, size_t size_of, size_t new_size)
{
	unsigned char	*new;

	if (size_of == new_size)
		return (ptr);
	new = (unsigned char *)malloc(new_size);
	if (new && ptr)
	{
		if (ptr && size_of > 0)
			ft_memcpy(new, ptr, ft_min_size_t(size_of, new_size));
		if (ptr)
			free(ptr);
	}
	return (new);
}
