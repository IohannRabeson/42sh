/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:23:26 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:54 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_str;
	char	*result;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	new_str = (char *)malloc(sizeof(*new_str) * (ft_strlen(str1)
				+ ft_strlen(str2) + 1));
	result = NULL;
	if (new_str)
	{
		result = new_str;
		ft_strcpy(new_str, str1);
		new_str += ft_strlen(str1);
		ft_strcpy(new_str, str2);
		new_str += ft_strlen(str2);
		*new_str = '\0';
	}
	return (result);
}
