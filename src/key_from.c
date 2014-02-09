/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_from.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:14:11 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 18:15:45 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include <unistd.h>
#include <term.h>

void	key_from_chars(t_key key, char c0, char c1, char c2, char c3)
{
	key[0] = c0;
	key[1] = c1;
	key[2] = c2;
	key[3] = c3;
}

void	key_from_str(t_key key, char const *str)
{
	t_ui	i;

	key_bzero(key);
	i = 0;
	if (str == NULL)
		return ;
	while (i < KEYCODE_SIZE && str[i] != '\0')
	{
		key[i] = str[i];
		++i;
	}
}
