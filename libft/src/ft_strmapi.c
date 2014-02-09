/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 05:03:46 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char			*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	count;
	size_t	i;
	char	*new_str;

	if (str == NULL || f == NULL)
		return (NULL);
	count = ft_strlen(str);
	i = 0;
	new_str = (char *)malloc(sizeof(*new_str) * count + 1);
	if (new_str)
	{
		while (i < count)
		{
			new_str[i] = (*f)(i, str[i]);
			i += 1;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
