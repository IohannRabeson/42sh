/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 03:06:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:54 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strlcmp(const char *left, const char *right)
{
	size_t	left_len;
	size_t	right_len;
	size_t	len;

	left_len = ft_strlen(left);
	right_len = ft_strlen(right);
	if (left_len >= right_len)
		len = left_len;
	else
		len = right_len;
	return (ft_strlncmp(left, right, len));
}
