/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node_query.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:18:37 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:21:15 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>

int				btree_node_is_leave(t_btree_node const *node)
{
	return (node && node->left == NULL && node->right == NULL);
}

int				btree_node_is_root(t_btree_node const *node)
{
	return (node && node->parent == NULL);
}
