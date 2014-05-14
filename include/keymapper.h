/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymapper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 19:23:46 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 19:25:52 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAPPER_H
# define KEYMAPPER_H
# include "key.h"

typedef	void(*t_func_action)();

typedef struct	s_keymap
{
	t_key			key;
	t_func_action	action;
}				t_keymap;

typedef struct	s_keymapper
{
	t_keymap	*keymaps;
	t_ui		keymap_count;
}				t_keymapper;

void			keymapper_init(t_keymapper *km);
void			keymapper_destroy(t_keymapper *km);
void			keymapper_load(t_keymapper *km, t_keymap const *keymaps);
t_bool			keymapper_map(t_keymapper const *km, t_key const key,
								void *obj);

#endif
