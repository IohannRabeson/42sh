/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 15:03:04 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:46:29 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_NODE_H
# define FT_BTREE_NODE_H
# include "ft_functional.h"

typedef enum	e_rb_child
{
	RBT_LEFT,
	RBT_RIGHT
}				t_rb_child;

typedef struct	s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*value;
}				t_btree_node;

t_btree_node	*btree_node_init(void *value);
void			btree_node_destroy(t_btree_node *node, t_del_func dfunc);
t_btree_node	*btree_node_parent(t_btree_node const *node);
t_btree_node	*btree_node_left(t_btree_node const *node);
t_btree_node	*btree_node_right(t_btree_node const *node);
int				btree_node_is_leave(t_btree_node const *node);
int				btree_node_is_root(t_btree_node const *node);
void			btree_node_set_child(t_btree_node *node, t_btree_node *child,
										t_rb_child lr);
int				btree_node_is_leave(t_btree_node const *node);
int				btree_node_is_root(t_btree_node const *node);
void			btree_node_prefix(t_btree_node *node, t_apl_func afunc);
void			btree_node_infix(t_btree_node *node, t_apl_func afunc);
void			btree_node_postfix(t_btree_node *node, t_apl_func afunc);

#endif
