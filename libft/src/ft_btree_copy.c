/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:23:50 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:53:49 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stddef.h>

static void	btree_copy_imp(t_btree *dest,
							t_btree const *src,
							t_btree_node *node,
							t_clone_func func)
{
	void	*new;

	if (node)
	{
		new = func(node->value);
		if (new == NULL)
			return ;
		btree_insert(dest, new);
		if (node->left)
			btree_copy_imp(dest, src, node->left, func);
		if (node->right)
			btree_copy_imp(dest, src, node->right, func);
	}
}

void		btree_copy(t_btree *dest, t_btree const *src,
						t_clone_func func)
{
	btree_copy_imp(dest, src, src->root, func);
}
