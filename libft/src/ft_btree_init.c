/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:17:54 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:15:30 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <string.h>

void	btree_init(t_btree *tree, t_del_func dfunc,
				   t_cmp_func cmp_func)
{
	tree->root = NULL;
	tree->dfunc = dfunc;
	tree->cmp_func = cmp_func;
}
