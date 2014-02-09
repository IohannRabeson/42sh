/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:21:17 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncat(char *dest, const char *source, size_t n)
{
	char	*result;
	size_t	i;

	i = 0;
	result = dest;
	while (*dest != '\0')
		dest += 1;
	while (*source != '\0' && i < n)
	{
		*dest = *source;
		++dest;
		++source;
		i += 1;
	}
	*dest = '\0';
	return (result);
}
