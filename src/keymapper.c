/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymapper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 19:27:01 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 01:58:10 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keymapper.h"
#include "terminal.h"
#include <stdlib.h>
#include <ft_memory.h>
#include <ft_error.h>

void	keymapper_init(t_keymapper *km)
{
	ft_bzero(km, sizeof(*km));
}

void	keymapper_destroy(t_keymapper *km)
{
	if (km->keymaps)
		free(km->keymaps);
	ft_bzero(km, sizeof(*km));
}

void	keymapper_load(t_keymapper *km, t_keymap const *keymaps)
{
	t_ui	count;
	t_ui	i;

	if (km->keymaps)
	{
		free(km->keymaps);
		km->keymaps = NULL;
	}
	if (keymaps == NULL)
		return ;
	count = 0;
	i = 0;
	while (keymaps[count].action != NULL)
		++count;
	km->keymaps = (t_keymap *)malloc(sizeof(t_keymap) * count);
	if (km->keymaps == NULL)
		exit_errorc("keymapper_load",
					ERRC_NOT_ENOUGH_MEMORY, 1, terminal_destroy);
	while (i < count)
	{
		km->keymaps[i] = keymaps[i];
		++i;
	}
	km->keymap_count = count;
}

t_bool	keymapper_map(t_keymapper const *km, t_key const key,
					  void *obj)
{
	t_ui	i;

	i = 0;
	while (i < km->keymap_count)
	{
		if (key_cmp(km->keymaps[i].key, key) == 0)
		{
			km->keymaps[i].action(obj);
			return (true);
		}
		++i;
	}
	return (false);
}
