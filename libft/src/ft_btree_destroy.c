/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:17:29 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:16:51 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>

void	btree_destroy(t_btree *tree)
{
	btree_node_destroy(tree->root, tree->dfunc);
	tree->root = NULL;
}
