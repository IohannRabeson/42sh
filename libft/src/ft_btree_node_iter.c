/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node_iter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:18:30 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:32:22 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_node.h"

inline static void	rbn_apply(t_btree_node *node, t_apl_func apl)
{
	apl(node->value);
}

void				btree_node_prefix(t_btree_node *node, t_apl_func apl)
{
	if (node)
	{
		rbn_apply(node, apl);
		if (node->left)
			btree_node_prefix(node->left, apl);
		if (node->right)
			btree_node_prefix(node->right, apl);
	}
}

void				btree_node_infix(t_btree_node *node, t_apl_func apl)
{
	if (node)
	{
		if (node->left)
			btree_node_infix(node->left, apl);
		rbn_apply(node, apl);
		if (node->right)
			btree_node_infix(node->right, apl);
	}
}

void				btree_node_postfix(t_btree_node *node, t_apl_func apl)
{
	if (node)
	{
		if (node->left)
			btree_node_postfix(node->left, apl);
		if (node->right)
			btree_node_postfix(node->right, apl);
		rbn_apply(node, apl);
	}
}
