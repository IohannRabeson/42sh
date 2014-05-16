/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 05:39:31 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/16 15:37:00 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_array.h"
#include <stdlib.h>

char	**str_array_malloc(t_ui size)
{
	char	**new_array;
	t_ui	i;

	new_array = (char **)malloc(sizeof(*new_array) * (size + 1));
	i = 0;
	if (new_array == NULL)
		return (NULL);
	while (i < size)
		new_array[i++] = NULL;
	new_array[i] = NULL;
	return (new_array);
}

char	**str_array_realloc(char **array, t_ui new_size)
{
	const t_ui	old_size = str_array_size(array);
	char		**new_array;
	t_ui		i;
	t_ui		max_i;

	new_array = (char **)malloc(sizeof(*new_array) * (new_size + 1));
	i = 0;
	max_i = (new_size < old_size) ? new_size : old_size;
	if (new_array == NULL)
		return (NULL);
	while (i < max_i)
	{
		new_array[i] = array[i];
		++i;
	}
	while (i <= new_size)
		new_array[i++] = NULL;
	free(array);
	return (new_array);
}

void	str_array_free(char **array)
{
	str_array_foreach(array, free);
	free(array);
}

t_ui	str_array_size(char **array)
{
	t_ui	i;

	i = 0;
	if (array == NULL)
		return (0);
	while (array[i] != NULL)
		++i;
	return (i);
}
