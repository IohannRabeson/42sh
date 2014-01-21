/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:17:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 20:25:09 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_app	*app_instance(void)
{
	static t_app app;

	return (&app);
}

void	app_init(int argc, char **argv, char **environs)
{
	t_app *const	app = app_instance();

	env_init(&app->env, environs);
	app->run = true;
	(void)argv;
	(void)argc;
}

void	app_destroy(void)
{
	t_app *const	app = app_instance();

	env_destroy(&app->env);
}

void	app_stop(void)
{
	t_app *const	app = app_instance();

	app->run = false;
}

t_bool	app_run(void)
{
	const t_app *const	app = app_instance();

	return (app->run);
}
