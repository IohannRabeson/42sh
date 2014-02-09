/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:17:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 18:54:06 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>

t_btree_node		*btree_find(t_btree const *tree, void *value)
{
	t_btree_node	*it;
	int				cmp_res;

	if (tree)
		it = tree->root;
	while (it != NULL)
	{
		cmp_res = tree->cmp_func(it->value, value);
		if (cmp_res == 0)
			return (it);
		else if (cmp_res < 0)
			it = it->right;
		else
			it = it->left;
	}
	return (NULL);
}
