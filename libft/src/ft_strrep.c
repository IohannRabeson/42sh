/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:34:31 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/16 15:35:23 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

t_bool		ft_strrep(char **origin,
						char const *replace,
						char const *replacement)
{
	t_ui	begin;
	t_ui	size;
	char	*res;

	if (ft_strfind(*origin, replace, &begin, &size))
	{
		res = ft_strnrep(*origin, begin, size, replacement);
		free(*origin);
		*origin = res;
		return (true);
	}
	else
	{
		return (false);
	}
}
