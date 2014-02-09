/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_minmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:18:12 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:22:04 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>

void			*btree_find_min(t_btree const *tree)
{
	t_btree_node const	*it;

	it = tree->root;
	while (it && it->left)
	{
		it = it->left;
	}
	if (it)
		return (it->value);
	else
		return (NULL);
}

void			*btree_find_max(t_btree const *tree)
{
	t_btree_node const	*it;

	it = tree->root;
	while (it && it->right)
	{
		it = it->right;
	}
	if (it)
		return (it->value);
	else
		return (NULL);
}
