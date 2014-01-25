/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:34:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:12:39 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdlib.h>

void			builtin_init(t_builtin *btin,
							 char const *key,
							 t_builtin_func func)
{
	btin->key = key;
	btin->func = func;
}

void			builtin_destroy(t_builtin *btin)
{
	btin->func = NULL;
}

char const		*builtin_key(t_builtin const *btin)
{
	return (btin->key);
}
