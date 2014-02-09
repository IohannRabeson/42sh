/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 15:13:13 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strnchr(char const *str, int c, size_t n)
{
	const char	real_char = (char)c;
	size_t		i;

	i = 0;
	while (i < n && str[i] != '\0' && str[i] != real_char)
		++i;
	if (*str == '\0' || i >= n)
		return (NULL);
	return ((char *)str + i);
}
