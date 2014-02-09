/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:32:59 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:08:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_error.h"

void				list_push_front(t_list *list, void *item)
{
	t_list_node	*node;

	node = (t_list_node *)malloc(sizeof(*node));
	if (node == NULL)
		exit_errorc("list_push_front", ERRC_NOT_ENOUGH_MEMORY, 1, NULL);
	list_node_init(node, item);
	list_node_set_next(node, list->first);
	list->first = node;
	if (list->last == NULL)
		list->last = node;
}

void				list_push_back(t_list *list, void *item)
{
	t_list_node	*node;

	node = (t_list_node *)malloc(sizeof(*node));
	if (node == NULL)
		exit_errorc("list_push_back", ERRC_NOT_ENOUGH_MEMORY, 1, NULL);
	list_node_init(node, item);
	list_node_set_prev(node, list->last);
	list->last = node;
	if (list->first == NULL)
		list->first = node;
}

void				list_pop_front(t_list *list)
{
	t_list_node	*new_first;

	if (list->first == NULL)
		return ;
	new_first = list->first->next;
	if (new_first)
		new_first->prev = NULL;
	if (list->first == list->last)
		list->last = new_first;
	list->first = new_first;
}

void				list_pop_back(t_list *list)
{
	t_list_node	*new_last;

	if (list->last == NULL)
		return ;
	new_last = list->last->prev;
	if (new_last)
		new_last->next = NULL;
	if (list->first == list->last)
		list->first = new_last;
	list->last = new_last;
}
