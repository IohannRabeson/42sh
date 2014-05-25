/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo_foreach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 21:58:55 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/24 22:44:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "histo.h"
#include <ft_list.h>

void			histo_cforeach(t_histo const *histo, t_histo_entry_cfunc func)
{
	t_list_node const	*it;
	t_ui				i;

	it = list_clast(&histo->str_list);
	i = 0;
	while (it)
	{
		func(i, (char const *)it->item);
		it = it->prev;
		++i;
	}
}

void			histo_foreach(t_histo *histo, t_histo_entry_func func)
{
	t_list_node	*it;
	t_ui		i;

	it = list_last(&histo->str_list);
	i = 0;
	while (it)
	{
		func(i, (char *)it->item);
		it = it->prev;
		++i;
	}
}
