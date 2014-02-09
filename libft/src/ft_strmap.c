/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:17:15 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:54 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char			*ft_strmap(char const *str, char (*f)(char))
{
	size_t	count;
	size_t	i;
	char	*new_str;

	if (str == NULL || f == NULL)
		return (NULL);
	count = ft_strlen(str);
	i = 0;
	new_str = (char *)malloc(sizeof(*new_str) * count + 1);
	if (new_str != NULL)
	{
		while (i < count)
		{
			new_str[i] = (*f)(str[i]);
			i += 1;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
