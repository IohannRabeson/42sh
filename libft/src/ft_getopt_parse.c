/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 03:50:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:40:07 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_getopt_flag.h"
#include <stdlib.h>

t_go_flag		*getopt_parse(t_getopt *getopt, char const *str, t_ui i)
{
	t_go_ftype		ftype;
	t_go_flag		*flag;

	ftype = GOFT_INVALID;
	flag = (t_go_flag *)malloc(sizeof(*flag));
	if (flag == NULL)
		return (NULL);
	ftype = go_flag_init(flag, str, i);
	if (ftype == GOFT_INVALID)
	{
		go_flag_destroy(flag);
		free(flag);
		flag = NULL;
	}
	else
		btree_insert(&getopt->flags, (void *)flag);
	return (flag);
}
