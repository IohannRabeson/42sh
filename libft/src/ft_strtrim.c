/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:01:26 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int			trim_ispace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static char const	*trim_find_begin(char const *str)
{
	while (*str != '\0' && trim_ispace(*str))
		++str;
	return (str);
}

static char const	*trim_find_end(char const *str)
{
	size_t		count;
	size_t		i;
	char const	*result;

	count = ft_strlen(str);
	i = 0;
	result = str + count;
	if (!trim_ispace(str[count - 1]))
		return (result);
	if (count > 0)
	{
		count -= 1;
		while (i < count)
		{
			result = str + (count - i);
			++i;
			if (!trim_ispace(str[count - i]))
				break ;
		}
	}
	return (result);
}

char				*ft_strtrim(char const *str)
{
	char const	*begin;
	char const	*end;
	char		*result;
	size_t		count;

	if (str == NULL)
		return (NULL);
	begin = trim_find_begin(str);
	end = trim_find_end(begin);
	count = (size_t)(end - begin);
	result = (char *)malloc(sizeof(*result) * (count + 1));
	if (result == NULL)
		return (NULL);
	if (ft_strncpy(result, begin, count) != NULL)
		result[count] = '\0';
	return (result);
}
