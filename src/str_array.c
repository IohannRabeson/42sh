/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:32:45 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 21:10:04 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_array.h"
#include <stdlib.h>

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

void	str_array_delete(char ***array)
{
	char 	**str_array;

	if (array == NULL || *array == NULL)
		return ;
	str_array = *array;
	while (*str_array != NULL)
		free(*str_array++);
	free(str_array);
	array = NULL;
}
