/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 06:09:08 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *str, int c)
{
	const char		real_char = (char)c;
	char			*result;

	result = NULL;
	while (*str != '\0')
	{
		if (*str == real_char)
		{
			result = (char *)str;
		}
		str += 1;
	}
	if (*str == real_char)
		result = (char *)str;
	return (result);
}
