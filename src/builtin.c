/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:34:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 08:30:23 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <ft_memory.h>

void			builtin_init(t_builtin *btin,
								char const *key,
								char const *help,
								t_builtin_func func)
{
	ft_bzero(btin, sizeof(*btin));
	btin->key = key;
	btin->help = help;
	btin->func = func;
}

void			builtin_destroy(t_builtin *btin)
{
	ft_bzero(btin, sizeof(*btin));
}

char const		*builtin_key(t_builtin const *btin)
{
	return (btin->key);
}
