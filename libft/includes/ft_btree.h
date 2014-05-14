/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 15:03:35 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:46:10 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# include "ft_btree_node.h"
# include "ft_functional.h"

typedef struct	s_btree
{
	t_btree_node	*root;
	t_del_func		dfunc;
	t_cmp_func		cmp_func;
}				t_btree;

void			btree_init(t_btree *tree, t_del_func dfunc,
							t_cmp_func cmp_func);
void			btree_destroy(t_btree *tree);
t_btree_node	*btree_insert(t_btree *tree, void *value);
void			btree_remove(t_btree *tree, void *value);
void			btree_erase(t_btree *tree, t_btree_node *node);
void			btree_clear(t_btree *tree);
void			btree_prefix(t_btree const *tree, t_apl_func afunc);
void			btree_infix(t_btree const *tree, t_apl_func afunc);
void			btree_postfix(t_btree const *tree, t_apl_func afunc);
int				btree_empty(t_btree const *tree);
unsigned int	btree_size(t_btree const *tree);
t_btree_node	*btree_find(t_btree const *tree, void *value);
void			*btree_find_min(t_btree const *tree);
void			*btree_find_max(t_btree const *tree);
int				btree_contains(t_btree const *tree, void *value);
void			btree_transfer_if(t_btree *dest, t_btree *src,
									t_filter_func f);
void			btree_copy(t_btree *dest, t_btree const *src,
							t_clone_func f);

#endif
