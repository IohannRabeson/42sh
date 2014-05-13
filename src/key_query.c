/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_query.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 22:10:05 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/13 16:19:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include <ft_string.h>

t_bool	key_is_char(t_key const key)
{
	return (key[1] == 0 && key[2] == 0 && ft_isprint(key[0]) && key[0] != 126);
}

char	key_get_char(t_key const key)
{
	if (key[0] == 13)
		return ('\r');
	return (key[0]);
}
