/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:22:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 17:45:47 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void				list_init(t_list *list, t_del_func dfunc)
{
	list->dfunc = dfunc;
	list->first = NULL;
	list->last = NULL;
}

void				list_destroy(t_list *list)
{
	list_clear(list);
}
