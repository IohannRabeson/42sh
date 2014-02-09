/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node_access.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:18:18 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:18:53 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>

t_btree_node	*btree_node_parent(t_btree_node const *node)
{
	if (node)
		return (node->parent);
	else
		return (NULL);
}

t_btree_node	*btree_node_left(t_btree_node const *node)
{
	if (node)
		return (node->left);
	else
		return (NULL);
}

t_btree_node	*btree_node_right(t_btree_node const *node)
{
	if (node)
		return (node->right);
	else
		return (NULL);
}

void			btree_node_set_child(t_btree_node *node, t_btree_node *child,
									 t_rb_child lr)
{
	if (node)
	{
		if (child)
			child->parent = node;
		if (lr == RBT_LEFT)
			node->left = child;
		else if (lr == RBT_RIGHT)
			node->right = child;
	}
}
