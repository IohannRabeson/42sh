/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 01:54:53 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:40:07 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_getopt_flag.h"
#include "ft_string.h"
#include <stdlib.h>

static int	go_flag_cmp(t_go_flag *left, t_go_flag *right)
{
	return (ft_strcmp(left->key, right->key));
}

static void	go_flag_destroy_imp(void *value)
{
	t_go_flag	*flag;

	flag = (t_go_flag *)value;
	go_flag_destroy(flag);
	free(flag);
}

void		getopt_init_args(t_getopt *getopt, int argc, char **argv)
{
	int			i;

	i = 1;
	getopt_init(getopt);
	while (i < argc)
	{
		getopt_parse(getopt, argv[i], i);
		++i;
	}
}

void		getopt_init(t_getopt *getopt)
{
	btree_init(&getopt->flags, &go_flag_destroy_imp, &go_flag_cmp);
}

void		getopt_destroy(t_getopt *getopt)
{
	btree_destroy(&getopt->flags);
}
