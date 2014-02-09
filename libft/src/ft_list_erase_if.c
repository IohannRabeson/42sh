/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_erase_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:45:11 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 15:49:38 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ui	list_erase_if(t_list *list, t_filter_func ffunc)
{
	t_ui		erased;
	t_list_node	*it;

	erased = 0;
	it = list_first(list);
	while (it)
	{
		if (ffunc(it->item))
		{
			it = list_erase(list, it);
			++erased;
		}
		else
		{
			it = it->next;
		}
	}
	return (erased);
}
