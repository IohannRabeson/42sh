/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 22:05:21 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:10:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_error.h"
#include <stdlib.h>

char	*ft_strndup(const char *str, size_t n)
{
	char	*new_str;
	size_t	count;
	size_t	i;

	if (str == NULL)
		return (NULL);
	count = ft_strlen(str);
	if (count > n)
		count = n;
	new_str = (char *)malloc(sizeof(*str) * (count + 1));
	if (new_str == NULL)
		exit_errorc("ft_strndup", ERRC_NOT_ENOUGH_MEMORY, 1, NULL);
	i = 0;
	if (new_str && i < n)
	{
		while (str[i] != '\0' && i < count)
		{
			new_str[i] = str[i];
			i += 1;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
