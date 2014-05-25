/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:17:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 06:44:18 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "builtin.h"
#include "terminal.h"
#include <ft_memory.h>
#include <ft_string.h>

t_app		*app_instance(void)
{
	static t_app app;

	return (&app);
}

void		app_destroy(void)
{
	t_app	*app;

	app = app_instance();
	builtins_destroy(&app->builtins);
	parser_destroy(&app->parser);
	gnl_destroy(&app->gnl);
	env_destroy(&app->vars);
	env_destroy(&app->env);
	getopt_destroy(&app->getopt);
	keymapper_destroy(&app->keymapper);
	textedit_destroy(&app->textedit);
	terminal_destroy();
	histo_save_config(&app->histo, FILE_HISTORY);
	histo_destroy(&app->histo);
	if (app->app_path)
		free(app->app_path);
	ft_bzero(app, sizeof(*app));
}
