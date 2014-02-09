/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 05:39:31 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:30:17 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_array.h"
#include <stdlib.h>

/*
**	Allocate an array of \e size + 1 strings.
**	The last string of the array is set to NULL and indicate
**	the end of the array.
**	For safety all of the items of the array are set to NULL.
*/
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

/*
**	Allocate an array of \e size + 1 strings and copy
**	the strings of \e array into it.
**	If the new array is greater than the old array, the news
**	cell allocated are filled by NULL.
*/
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

/*
**	Free an array of string terminated by a null string.
**	Each string in the array are freed, and <i>array</i> too.
*/
void	str_array_free(char **array)
{
	str_array_foreach(array, free);
	free(array);
}

/*
**	Count strings of an array of string treminated by a null string.
*/
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
