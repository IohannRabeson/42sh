/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 04:52:43 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char			*ft_strnew(size_t size)
{
	char	*new_str;
	size_t	i;

	new_str = (char *)malloc(sizeof(*new_str) * (size + 1));
	i = 0;
	if (new_str)
	{
		while (i < size)
		{
			new_str[i] = '\0';
			i += 1;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
