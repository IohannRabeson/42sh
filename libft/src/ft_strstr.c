/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:43:22 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strstr(char *source, const char *search)
{
	size_t	search_len;
	size_t	source_len;

	search_len = ft_strlen(search);
	source_len = ft_strlen(source);
	if (source_len < search_len)
		return (NULL);
	if (search_len == 0 || source_len == 0)
		return (source);
	while (*source != '\0')
	{
		if (ft_strncmp(source, search, search_len) == 0)
			return (source);
		source += 1;
	}
	return (NULL);
}
