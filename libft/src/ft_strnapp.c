/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnapp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 07:02:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strnapp(char const *origin, char const *str, size_t n)
{
	char	*result;
	size_t	org_len;
	char	*it;

	org_len = ft_strlen(origin);
	result = (char *)malloc(sizeof(*result) * (org_len + n + 1));
	if (result)
	{
		it = result;
		if (origin)
		{
			ft_strcpy(it, origin);
			it += org_len;
		}
		if (str)
		{
			ft_strncpy(it, str, n);
			if (n > ft_strlen(str))
				it += n;
			else
				it += ft_strlen(str);
		}
	}
	return (result);
}
