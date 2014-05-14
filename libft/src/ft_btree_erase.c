/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:17:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:54:15 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>
#include <stdlib.h>

static t_btree_node	*find_minimum(t_btree_node *node)
{
	if (node->left == NULL)
		return (node);
	else
		return (find_minimum(node->left));
}

static t_btree_node	*successor(t_btree_node *node)
{
	t_btree_node	*it;

	if (node->right)
		return (find_minimum(node->right));
	it = node->parent;
	while (it && node != it->right)
	{
		node = it;
		it = it->parent;
	}
	return (it);
}

static void			cleanup(t_btree *tree, t_btree_node *node, t_btree_node *y)
{
	if (tree->dfunc)
		(*tree->dfunc)(node->value);
	node->value = y->value;
	free(y);
}

void				btree_erase(t_btree *tree, t_btree_node *node)
{
	t_btree_node	*x;
	t_btree_node	*to_destroy;

	if (node == NULL)
		return ;
	if (btree_node_is_leave(node))
		to_destroy = node;
	else
		to_destroy = successor(node);
	if (to_destroy->left)
		x = to_destroy->left;
	else
		x = to_destroy->right;
	if (x)
		x->parent = to_destroy->parent;
	if (to_destroy->parent == NULL)
		tree->root = x;
	else
	{
		if (to_destroy == to_destroy->parent->left)
			to_destroy->parent->left = x;
		else
			to_destroy->parent->right = x;
	}
	cleanup(tree, node, to_destroy);
}
