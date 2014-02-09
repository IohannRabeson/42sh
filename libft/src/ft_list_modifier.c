/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:56:14 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:07:50 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_error.h"
#include <stdlib.h>

void				list_insert(t_list *list, t_list_node *at, void *item)
{
	t_list_node	*next;
	t_list_node	*prev;
	t_list_node	*node;

	node = (t_list_node *)malloc(sizeof(*node));
	if (node == NULL)
		exit_errorc("list_insert", ERRC_NOT_ENOUGH_MEMORY, 1, NULL);
	list_node_init(node, item);
	next = at;
	prev = at->prev;
	list_node_set_next(node, next);
	list_node_set_prev(node, prev);
	if (at == list->first)
		list->first = node;
	if (at == list->last)
		list->last = node;
}

t_list_node			*list_erase(t_list *list, t_list_node *node)
{
	t_list_node	*next;
	t_list_node	*prev;

	if (node == NULL)
		return (NULL);
	next = node->next;
	prev = node->prev;
	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
	if (node == list->first)
		list->first = next;
	if (node == list->first)
		list->last = prev;
	list_node_destroy(node, list->dfunc);
	free(node);
	return (next);
}

void				list_clear(t_list *list)
{
	t_list_node	*it;
	t_list_node	*next;

	it = list->first;
	next = NULL;
	while (it)
	{
		next = it->next;
		list_node_destroy(it, list->dfunc);
		free(it);
		it = next;
	}
	list->first = NULL;
	list->last = NULL;
}
