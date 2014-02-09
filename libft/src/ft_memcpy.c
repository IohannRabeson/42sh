/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:22:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (dest && str)
	{
		i = 0;
		str1 = (unsigned char *)dest;
		str2 = (unsigned char *)str;
		while (i < n)
		{
			str1[i] = str2[i];
			i += 1;
		}
	}
	return ((void *)dest);
}
