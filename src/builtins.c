/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:31:01 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:05:32 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "builtin.h"
#include <ft_memory.h>
#include <ft_error.h>
#include <ft_minmax.h>
#include <stdlib.h>

void	builtins_init(t_builtins *bts)
{
	ft_bzero(bts, sizeof(*bts));
	builtins_reserve(bts, 16);
}

void	builtins_destroy(t_builtins *bts)
{
	if (bts->builtins)
	{
		free(bts->builtins);
		bts->builtins = NULL;
	}
	ft_bzero(bts, sizeof(*bts));
}

void	builtins_reserve(t_builtins *bts, t_ui new_cap)
{
	t_builtin	*new_blt;

	if (new_cap == bts->capacity)
		return ;
	new_blt = ft_realloc(bts->builtins, sizeof(*bts->builtins) * bts->size,
							sizeof(*new_blt) * new_cap);
	if (new_blt == NULL)
		exit_errorc(ERRC_NOT_ENOUGH_MEMORY);
	bts->builtins = new_blt;
	bts->size = ft_min_uint(new_cap, bts->size);
	bts->capacity = new_cap;
}

void	builtins_clear(t_builtins *bts)
{
	bts->size = 0;
}
