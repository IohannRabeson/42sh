/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 03:51:34 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:48:28 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void				list_foreach(t_list *list, t_apl_func afunc)
{
	t_list_node	*it;

	it = list->first;
	while (it != NULL)
	{
		afunc(it->item);
		it = it->next;
	}
}

void				list_cforeach(t_list const *list, t_apl_func afunc)
{
	t_list_node const	*it;

	it = list->first;
	while (it != NULL)
	{
		afunc(it->item);
		it = it->next;
	}
}
