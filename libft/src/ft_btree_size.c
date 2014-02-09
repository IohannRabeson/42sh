/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:18:58 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:21:35 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static unsigned int		node_size_count(t_btree_node const *node,
										unsigned int count)
{
	count += 1;
	if (node->left)
		count = node_size_count(node->left, count);
	if (node->right)
		count = node_size_count(node->right, count);
	return (count);
}

unsigned int			btree_size(t_btree const *tree)
{
	if (tree && tree->root)
		return (node_size_count(tree->root, 0));
	else
		return (0);
}
