/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:39:14 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:21:27 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memccpy(void *dest, const void *str, char c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)str;
	if (str1 && str2)
	{
		while (i < n)
		{
			str1[i] = str2[i];
			if (str2[i] == (unsigned char)c)
				return ((void *)(str1 + i + 1));
			i += 1;
		}
	}
	return (NULL);
}
