/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:11:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/24 00:12:05 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <ft_string.h>
#include <ft_print.h>
#include <ft_memory.h>
#include <stdlib.h>
#include <unistd.h>

t_bool				app_run(void)
{
	t_app	*app;
	t_key	key;

	app = app_instance();
	key_bzero(key); 
	if (app->run == false)
		return (false);
	key_read(key, 0);
	if (key_is_char(key))
		cursor_insert(&app->textedit, key_get_char(key));
	else
		keymapper_map(&app->keymapper, key, &app->textedit);
	if (app->run)
		textedit_display(&app->textedit);
	return (app->run);
}
