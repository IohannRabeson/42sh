/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 21:55:19 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:12:40 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "textedit.h"

static const t_keymap	g_keymaps[] =
{
	{{10, 0, 0, 0}, textedit_validate},
	{{127, 0, 0, 0}, cursor_backspace},
	{{27, 91, 51, 126}, cursor_suppr},
	{{27, 91, 65, 0}, recall_prev},
	{{27, 91, 66, 0}, recall_next},
	{{27, 91, 68, 0}, cursor_prev_char},
	{{53, 67, 0, 0}, cursor_next_word},
	{{53, 68, 0, 0}, cursor_prev_word},
	{{27, 91, 67, 0}, cursor_next_char},
	{{0, 0, 0, 0}, NULL}
};

void		app_init_keymaps(t_app *app)
{
	keymapper_load(&app->keymapper, g_keymaps);
}
