/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:35:47 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 05:30:06 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_node.h"
#include <stdlib.h>

void	list_node_init(t_list_node *node, void *item)
{
	node->prev = NULL;
	node->next = NULL;
	node->item = item;
}

void	list_node_destroy(t_list_node *node, t_del_func dfunc)
{
	if (dfunc && node->item)
	{
		dfunc(node->item);
		node->item = NULL;
	}
	node->prev = NULL;
	node->next = NULL;
}

void	list_node_set_next(t_list_node *node, t_list_node *new_next)
{
	if (node == NULL)
		return ;
	if (node->next)
		node->next->prev = NULL;
	node->next = new_next;
	if (node->next)
		node->next->prev = node;
}

void	list_node_set_prev(t_list_node *node, t_list_node *new_prev)
{
	if (node == NULL)
		return ;
	if (node->prev)
		node->prev->next = NULL;
	node->prev = new_prev;
	if (node->prev)
		node->prev->next = node;
}
