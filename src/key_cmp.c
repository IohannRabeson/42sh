/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:28:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 19:21:15 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int	key_cmp(t_key const key_a, t_key const key_b)
{
	t_ui	i;

	i = 0;
	while (i < KEYCODE_SIZE)
	{
		if (key_a[i] != key_b[i])
			return (key_a[i] - key_b[i]);
		++i;
	}
	return (0);
}
