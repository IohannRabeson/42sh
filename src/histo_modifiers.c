/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 22:46:39 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 05:26:50 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "histo.h"

void			histo_pop_last(t_histo *histo)
{
	if (list_empty(&histo->str_list))
		return ;
	list_pop_front(&histo->str_list);
	histo->current = NULL;
}

void			histo_clear(t_histo *histo)
{
	list_clear(&histo->str_list);
	histo->current = NULL;
}

void			histo_remove(t_histo *histo, t_ui i)
{
	t_ui			j;
	t_list_node		*it;

	j = 0;
	it = list_last(&histo->str_list);
	while (it && j < i)
	{
		it = it->prev;
		++j;
	}
	if (it)
	{
		list_erase(&histo->str_list, it);
		histo->current = NULL;
		str_buf_clear(&histo->temp_cmdline);
	}
}
