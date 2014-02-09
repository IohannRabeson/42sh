/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:40:26 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:03 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *str, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	*temp;

	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)str;
	temp = (unsigned char *)malloc(sizeof(*temp) * n);
	if (temp)
	{
		while (i < n)
		{
			temp[i] = str2[i];
			i += 1;
		}
		i = 0;
		while (i < n)
		{
			str1[i] = temp[i];
			i += 1;
		}
		free(temp);
	}
	return ((void *)dest);
}
