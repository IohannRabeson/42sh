/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_foreach.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:50:02 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 18:42:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_array.h"
#include <stdlib.h>

/*
**	Call function \e afunc with each string of an array of string terminated
**	by a null string.
*/
void	str_array_foreach(char **array, t_apl_func afunc)
{
	const t_ui	count = str_array_size(array);
	t_ui		i;

	i = 0;
	if (array == NULL || *array == NULL)
		return ;
	while (i < count)
		afunc(array[i++]);
}
