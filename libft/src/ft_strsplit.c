/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 10:46:55 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int		next_word(char const *str_it, char const **begin,
						  char const **end, char sep)
{
	(*begin) = 0;
	(*end) = 0;
	while (*str_it != '\0' && *str_it == sep)
		str_it = str_it + 1;
	if (*str_it != '\0')
		(*begin) = str_it;
	while (*str_it != '\0' && *str_it != sep)
		str_it = str_it + 1;
	if ((*begin) != '\0')
		(*end) = str_it;
	return (*begin != '\0');
}

static int		count_word(char const *str, char sep)
{
	int	word_count;

	word_count = 0;
	while (*str != '\0')
	{
		while (*str == sep)
			str = str + 1;
		if (*str != '\0')
			word_count = word_count + 1;
		while (*str != sep && *str != '\0')
			str = str + 1;
	}
	return (word_count);
}

static char		*extract_str(char const *begin, char const *end)
{
	char	*result;
	int		i;

	if (begin == 0 || end == 0)
		return (NULL);
	i = 0;
	result = malloc(sizeof(*result) * ((end - begin) + 1));
	if (result == NULL)
		return (NULL);
	while (begin != end)
	{
		result[i] = *begin;
		begin = begin + 1;
		i = i + 1;
	}
	result[i] = '\0';
	return (result);
}

char			**ft_strsplit(char const *str, char sep)
{
	char		**array_ptr;
	int			word_count;
	int			i;
	char const	*begin;
	char const	*end;

	if (!str)
		return (NULL);
	word_count = count_word(str, sep);
	array_ptr = (char **)malloc(sizeof(*array_ptr) * (word_count + 1));
	i = 0;
	end = str;
	while (i < word_count)
	{
		next_word(end, &begin, &end, sep);
		array_ptr[i] = extract_str(begin, end);
		i = i + 1;
	}
	array_ptr[i] = NULL;
	return (array_ptr);
}
