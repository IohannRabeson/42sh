/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 00:07:41 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 01:47:47 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_node			*list_first(t_list *list)
{
	return (list->first);
}

t_list_node			*list_last(t_list *list)
{
	return (list->last);
}

t_list_node	const	*list_cfirst(t_list const *list)
{
	return (list->first);
}

t_list_node const	*list_clast(t_list const *list)
{
	return (list->last);
}
