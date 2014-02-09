/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:26:42 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	unsigned int	new_len;
	char			*new_str;

	if (str == NULL)
			return (NULL);
	new_len = (len - start);
	new_str = (char *)malloc(sizeof(*new_str) * (new_len + 1));
	if (new_str)
	{
		ft_strncpy(new_str, str + start, len);
		new_str[len] = '\0';
	}
	return (new_str);
}
