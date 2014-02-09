/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:18:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 18:19:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_btree_node.h"
#include <ft_memory.h>
#include <stdlib.h>

t_btree_node	*btree_node_init(void *value)
{
	t_btree_node	*node;

	node = (t_btree_node *)malloc(sizeof(*node));
	if (node)
	{
		ft_bzero(node, sizeof(*node));
		node->value = value;
	}
	return (node);
}

/*
**	Destroy each node recursively using \e dfunc.
*/
void		btree_node_destroy(t_btree_node *node, t_del_func dfunc)
{
	if (node)
	{
		if (node->left)
		{
			btree_node_destroy(node->left, dfunc);
			node->left = NULL;
		}
		if (node->right)
		{
			btree_node_destroy(node->right, dfunc);
			node->right = NULL;
		}
		if (node->value)
		{
			if (dfunc)
				dfunc(node->value);
			node->value = NULL;
		}
		free(node);
	}
}
