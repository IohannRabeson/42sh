/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:56:28 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 19:58:37 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "builtin.h"

void	builtins_add(t_builtins *bts, t_builtin const *bt)
{
	if (bts->size == bts->capacity)
		builtins_reserve(bts, bts->capacity * 2);
	bts->builtins[bts->size++] = *bt;
}
