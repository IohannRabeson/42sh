/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:54:13 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:21:22 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str_ptr;
	size_t			i;

	str_ptr = (unsigned char *)str;
	if (str)
	{
		i = 0;
		while (i < n)
		{
			if (*str_ptr == (unsigned char)c)
				return ((void *)str_ptr);
			i += 1;
			str_ptr += 1;
		}
	}
	return (NULL);
}
