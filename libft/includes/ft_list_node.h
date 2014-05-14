/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_node.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:34:04 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:50:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_NODE_H
# define FT_LIST_NODE_H
# include "ft_functional.h"

typedef struct	s_list_node
{
	struct s_list_node	*prev;
	struct s_list_node	*next;
	void				*item;
}				t_list_node;

void			list_node_init(t_list_node *node, void *item);
void			list_node_destroy(t_list_node *node, t_del_func dfunc);
void			list_node_set_next(t_list_node *node, t_list_node *new_next);
void			list_node_set_prev(t_list_node *node, t_list_node *new_prev);

#endif
