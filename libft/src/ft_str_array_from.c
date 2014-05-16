/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_from.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:13:50 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/16 14:55:45 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_array.h"
#include "ft_list.h"
#include "ft_string.h"

char	**str_array_from_array(int count, char **strs)
{
	char	**new_array;
	int		i;

	new_array = str_array_malloc((t_ui)count);
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (strs[i])
			new_array[i] = ft_strdup(strs[i]);
		++i;
	}
	new_array[i] = NULL;
	return (new_array);
}

char	**str_array_from_list(t_list const *str_list)
{
	t_ui const			count = list_count(str_list);
	char				**new_array;
	t_list_node const	*it;
	t_ui				i;

	new_array = str_array_malloc(count);
	if (new_array == NULL)
		return (NULL);
	it = list_cfirst(str_list);
	i = 0;
	while (it)
	{
		new_array[i] = ft_strdup((char *)it->item);
		++i;
		it = it->next;
	}
	new_array[count] = NULL;
	return (new_array);
}
