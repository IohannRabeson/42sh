/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:18:48 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:21:27 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>

void			btree_remove(t_btree *tree, void *value)
{
	t_btree_node	*node;

	node = btree_find(tree, value);
	if (node != NULL)
		btree_erase(tree, node);
}
