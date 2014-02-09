/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:34:56 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:03 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t			i;
	unsigned char	*str_ptr;

	i = 0;
	if (ptr)
	{
		str_ptr = (unsigned char *)ptr;
		while (i < len)
		{
			str_ptr[i] = (unsigned char)value;
			i += 1;
		}
	}
	return ((void *)ptr);
}
