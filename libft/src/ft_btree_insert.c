/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:17:18 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:54:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>

static int			get_insert_pos_imp(t_btree_node **node, const int cmp,
										t_rb_child *lr)
{
	t_btree_node	*next;

	if (cmp <= 0)
	{
		next = (*node)->right;
		if (next == NULL)
		{
			*lr = RBT_RIGHT;
			return (1);
		}
	}
	else
	{
		next = (*node)->left;
		if (next == NULL)
		{
			*lr = RBT_LEFT;
			return (1);
		}
	}
	(*node) = next;
	return (0);
}

static t_btree_node	*get_insert_pos(t_btree *tree, void *value,
									t_rb_child *lr)
{
	t_btree_node	*it;
	int				cmp;

	it = tree->root;
	while (it != NULL)
	{
		cmp = tree->cmp_func(it->value, value);
		if (get_insert_pos_imp(&it, cmp, lr))
			return (it);
	}
	return (NULL);
}

t_btree_node		*btree_insert(t_btree *tree, void *value)
{
	t_btree_node	*node;
	t_btree_node	*it;
	t_rb_child		left_or_right;

	if (!tree)
		return (NULL);
	if (tree->root)
	{
		node = btree_node_init(value);
		if (node == NULL)
			return (NULL);
		it = get_insert_pos(tree, value, &left_or_right);
		if (it == NULL)
			return (NULL);
		btree_node_set_child(it, node, left_or_right);
	}
	else
	{
		node = btree_node_init(value);
		if (node)
			tree->root = node;
	}
	return (node);
}
