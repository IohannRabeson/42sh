/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:46:38 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 19:48:31 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "builtin.h"
#include <ft_string.h>

t_builtin	*builtins_find(t_builtins const *bts, char const *key)
{
	t_ui	i;

	i = 0;
	while (i < bts->size)
	{
		if (ft_strequ(key, bts->builtins[i].key))
			return (&bts->builtins[i]);
		++i;
	}
	return (NULL);
}
