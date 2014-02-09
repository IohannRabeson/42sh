/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 05:57:29 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:53 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcpy_it(char *it, char const *str)
{
	if (it == NULL)
		return (NULL);
	while (str && *str != '\0')
		*it++ = *str++;
	return (it);
}
