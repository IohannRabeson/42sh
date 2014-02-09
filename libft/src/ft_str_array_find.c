/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_find.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:08:54 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/26 17:43:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_array.h"
#include "ft_string.h"

t_bool	str_array_find(char **array, char const *str, t_ui *index)
{
	t_ui	i;

	i = 0;
	if (array == NULL)
		return (false);
	while (array[i])
	{
		if (ft_strequ(array[i], str))
		{
			if (index)
				*index = i;
			return (true);
		}
		++i;
	}
	return (false);
}
