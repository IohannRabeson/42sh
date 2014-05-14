/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_transfer_if.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:19:04 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:56:01 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stddef.h>

static void		transfer_if(t_btree *dest, t_btree *src, t_filter_func func,
							t_btree_node *node)
{
	int	cond;

	cond = 0;
	if (node)
	{
		if (func(node->value))
		{
			if (btree_insert(dest, node->value))
				cond = 1;
		}
		if (node->left)
			transfer_if(dest, src, func, node->left);
		if (node->right)
			transfer_if(dest, src, func, node->right);
		if (cond)
		{
			node->value = NULL;
			btree_erase(src, node);
		}
	}
}

void			btree_transfer_if(t_btree *dest, t_btree *src,
									t_filter_func func)
{
	transfer_if(dest, src, func, src->root);
}
