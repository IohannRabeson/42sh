/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:55:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/24 00:05:53 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_error.h"
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
	if (new_str == NULL)
		exit_errorc("ft_strdup", ERRC_NOT_ENOUGH_MEMORY, 1, NULL);
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
