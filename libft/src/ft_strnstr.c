/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:29:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(char *source, const char *search, size_t n)
{
	size_t	search_len;
	size_t	source_len;
	size_t	i;

	search_len = ft_strlen(search);
	source_len = ft_strlen(source);
	if (source_len < search_len)
		return (NULL);
	if (search_len == 0 || source_len == 0)
		return (source);
	i = 0;
	if (n < search_len)
		return (NULL);
	while (*source != '\0' && i < n)
	{
		if (ft_strncmp(source, search, search_len) == 0)
			return (source);
		source += 1;
	}
	return (NULL);
}
