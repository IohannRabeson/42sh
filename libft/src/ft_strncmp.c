/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:30:16 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	strcmp_make_result(char left, char right)
{
	if (left > right)
		return (1);
	else if (left < right)
		return (-1);
	else
		return (0);
}

int			ft_strncmp(const char *left, const char *right, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	if (n == 1 && *left == *right)
		return (0);
	while (left[i] != '\0' && right[i] != '\0'
			&& left[i] == right[i])
	{
		if (i + 1 == n)
			return (strcmp_make_result(left[i], right[i]));
		i += 1;
	}
	return (strcmp_make_result(left[i], right[i]));
}
