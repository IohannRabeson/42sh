/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:07:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:16:03 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_stop(void)
{
	t_app *app;

	app = app_instance();
	app->run = false;
	app->exit_code = 0;
}

void	app_exit(int code)
{
	t_app *app;

	app = app_instance();
	app->run = false;
	app->exit_code = code;
}

void	recall_prev(t_textedit *te)
{
	histo_show_prev(&app_instance()->histo, te);
}

void	recall_next(t_textedit *te)
{
	histo_show_next(&app_instance()->histo, te);
}
