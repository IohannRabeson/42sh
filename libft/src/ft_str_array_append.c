/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_append.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:27:55 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 02:07:39 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_array.h"
#include <stdlib.h>
#include <ft_string.h>

char	**str_array_append(char **array, char const *str)
{
	const t_ui	old_count = str_array_size(array);
	char		**new_array;

	new_array = str_array_realloc(array, old_count + 1);
	if (new_array == NULL)
		return (NULL);
	new_array[old_count] = ft_strdup(str);
	return (new_array);
}
