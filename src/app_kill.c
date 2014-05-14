/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_kill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 01:26:58 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:16:25 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <signal.h>

void		app_kill_cmd(int sig)
{
	t_app *app;

	app = app_instance();
	if (app->current_cmd != 0)
		kill(app->current_cmd, sig);
}
