/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:54:47 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:50:05 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "builtin.h"

void	builtins_load(t_builtins *bts, struct s_builtin const *builtin)
{
	while (builtin && builtin->key && builtin->func)
	{
		builtins_add(bts, builtin);	
		++builtin;
	}
}
