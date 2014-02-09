/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:21:50 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:23:25 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

static size_t	strlcat_strnlen(const char *str, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		++i;
		++len;
	}
	return (len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = strlcat_strnlen(dst, maxlen);
	if (dest_len == maxlen)
		return (maxlen + src_len);
	if (src_len < maxlen - dest_len)
		ft_memcpy(dst + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dest_len, src, maxlen - dest_len - 1);
		dst[maxlen - 1] = '\0';
	}
	return (dest_len + src_len);
}
