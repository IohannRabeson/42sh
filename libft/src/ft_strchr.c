/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:06:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:53 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *str, int c)
{
	const char	real_char = (char)c;

	while (*str != real_char)
	{
		if (*str == '\0')
			return (NULL);
		str += 1;
	}
	return ((char *)str);
}
