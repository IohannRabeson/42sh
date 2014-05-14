/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:09:41 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:49:31 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include "ft_list_node.h"
# include "ft_functional.h"
# include "ft_types_def.h"
# include <stdlib.h>

typedef struct		s_list
{
	t_del_func	dfunc;
	t_list_node	*first;
	t_list_node	*last;
}					t_list;

void				list_init(t_list *list, t_del_func dfunc);
void				list_destroy(t_list *list);
t_ui				list_count(t_list const *list);
t_bool				list_empty(t_list const *list);
void				list_push_front(t_list *list, void *item);
void				list_push_back(t_list *list, void *item);
void				list_pop_front(t_list *list);
void				list_pop_back(t_list *list);
void				list_insert(t_list *list, t_list_node *at, void *item);
t_list_node			*list_erase(t_list *list, t_list_node *node);
void				list_clear(t_list *list);
t_list_node			*list_first(t_list *list);
t_list_node			*list_last(t_list *list);
t_list_node	const	*list_cfirst(t_list const *list);
t_list_node const	*list_clast(t_list const *list);
void				list_foreach(t_list *list, t_apl_func afunc);
void				list_cforeach(t_list const *list, t_apl_func afunc);
t_ui				list_erase_if(t_list *list, t_filter_func ffunc);

#endif
