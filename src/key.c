/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:02:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 15:11:09 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include <unistd.h>
#include <ft_memory.h>
#include <ft_print.h>

void	key_bzero(t_key key)
{
	ft_bzero(key, sizeof(char) * KEYCODE_SIZE);
}

t_bool	key_read(t_key key, int fd)
{
	key_bzero(key);
	return (read(fd, key, KEYCODE_SIZE) > 0);
}

void	key_put(t_key const key)
{
	t_ui	i;

	i = 0;
	while (i < KEYCODE_SIZE)
	{
		if (i > 0)
			ft_putstr(" - ");
		ft_putnbr(key[i]);
		++i;
	}
	ft_putchar('\n');
}
