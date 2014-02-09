/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_align.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 23:07:48 by irabeson          #+#    #+#             */
/*   Updated: 2013/12/15 17:37:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"
#include <libft.h>
#include <stdlib.h>

inline static size_t	min_ui(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

inline static size_t	compute_offset(size_t src_len, size_t size,
									   t_align align)
{
	size_t	free_space;

	if (size > src_len)
		free_space = size - src_len;
	else
		free_space = 0;
	if (align == AL_LEFT)
		return (0);
	else if (align == AL_CENTER)
		return (free_space / 2);
	else if (align == AL_RIGHT)
		return (free_space);
	else
		return (0);
}

char					*ft_format_align(char const *source, size_t size,
										 t_align align)
{
	char	*results;
	size_t	offset;
	size_t	i;

	i = 0;
	results = (char *)malloc(sizeof(*results) * (size + 1));
	if (results)
	{
		while (i < size)
			results[i++] = ' ';
		results[i] = '\0';
		if (source)
		{
			offset = compute_offset(ft_strlen(source), size, align);
			i = 0;
			while (source[i] != '\0')
			{
				results[i + offset] = source[i];
				++i;
			}
		}
	}
	return (results);
}
