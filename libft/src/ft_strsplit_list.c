/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 01:10:41 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 05:50:57 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_list.h"
#include "ft_str_array.h"
#include <stdlib.h>

t_ui	ft_strsplit_list(char const *str, char c, t_list *results)
{
	char	**temp_array;
	char	**it;
	t_ui	i;

	temp_array = ft_strsplit(str, c);
	it = temp_array;
	i = 0;
	while (it && *it)
	{
		list_push_back(results, (void *)ft_strdup(*it));
		++it;
		++i;
	}
	str_array_free(temp_array);
	return (i);
}
