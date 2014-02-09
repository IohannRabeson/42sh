/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 02:43:19 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:54 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	strlncmp_make_result(char left, char right)
{
	if (left > right)
		return (1);
	else if (left < right)
		return (-1);
	else
		return (0);
}

int			ft_strlncmp(const char *left, const char *right, size_t n)
{
	size_t	i;
	char	l;
	char	r;

	if (n == 0)
		return (0);
	i = 0;
	if (n == 1 && *left == *right)
		return (0);
	l = ft_tolower(left[i]);
	r = ft_tolower(right[i]);
	while (l != '\0' && r != '\0'
			&& l == r)
	{
		if (i + 1 == n)
			return (strlncmp_make_result(l, r));
		i += 1;
		l = ft_tolower(left[i]);
		r = ft_tolower(right[i]);
	}
	return (strlncmp_make_result(l, r));
}
