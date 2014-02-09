/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:55:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:54 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	count;
	size_t	i;

	count = ft_strlen(str);
	if (!str)
		return (NULL);
	new_str = (char *)malloc(sizeof(*str) * (count + 1));
	if (new_str)
	{
		i = 0;
		while (str[i] != '\0' && i < count)
		{
			new_str[i] = str[i];
			i += 1;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
