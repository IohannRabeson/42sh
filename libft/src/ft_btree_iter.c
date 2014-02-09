/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:18:06 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:18:22 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void		btree_prefix(t_btree const *tree, t_apl_func apl)
{
	if (apl && tree && tree->root)
		btree_node_prefix(tree->root, apl);
}

void		btree_infix(t_btree const *tree, t_apl_func apl)
{
	if (apl && tree && tree->root)
		btree_node_infix(tree->root, apl);
}

void		btree_postfix(t_btree const *tree, t_apl_func apl)
{
	if (apl && tree && tree->root)
		btree_node_postfix(tree->root, apl);
}
