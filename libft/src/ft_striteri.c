/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 05:01:24 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:22:54 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void			ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	size_t	count;
	size_t	i;

	if (str && f)
	{
		count = ft_strlen(str);
		i = 0;
		while (i < count)
		{
			(*f)(i, &str[i]);
			i += 1;
		}
	}
}
