/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 03:30:02 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:40:07 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_getopt_flag.h"
#include <stddef.h>

inline static t_go_flag	*find_flag(t_getopt const *getopt, char const *flag)
{
	t_btree_node	*node;
	t_go_flag	go_flag;

	go_flag.key = (char *)flag;
	go_flag.value = NULL;
	go_flag.type = GOFT_INVALID;
	node = btree_find(&getopt->flags, (void *)&go_flag);
	if (node)
		return ((t_go_flag *)node->value);
	else
		return (NULL);
}

int		getopt_contains(t_getopt const *getopt, char const *flag)
{
	return (find_flag(getopt, flag) != NULL);
}

int		getopt_hasvalue(t_getopt const *getopt, char const *flag)
{
	t_go_flag	*go_flag;

	go_flag = find_flag(getopt, flag);
	if (go_flag)
		return (go_flag->value != NULL);
	else
		return (0);
}

char	*getopt_value(t_getopt const *getopt, char const *flag)
{
	t_go_flag	*go_flag;

	go_flag = find_flag(getopt, flag);
	if (go_flag)
		return (go_flag->value);
	else
		return (NULL);
}
