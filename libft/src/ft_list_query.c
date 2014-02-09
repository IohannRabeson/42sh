/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_query.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 00:11:01 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 01:49:27 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_bool				list_empty(t_list const *list)
{
	return (list->first == NULL);
}

t_ui				list_count(t_list const *list)
{
	t_ui		i;
	t_list_node	*it;

	i = 0;
	it = list->first;
	if (it == NULL)
		return (0);
	while (it)
	{
		it = it->next;
		++i;
	}
	return (i);
}
