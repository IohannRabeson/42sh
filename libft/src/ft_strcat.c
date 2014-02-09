/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:41:14 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:53 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(char *dest, const char *source)
{
	size_t	len;
	char	*result;

	len = ft_strlen(source);
	result = ft_strncat(dest, source, len);
	return (result);
}
