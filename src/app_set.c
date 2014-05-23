/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 00:06:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/23 17:05:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <ft_error.h>
#include <ft_string.h>

void			app_set_last_cmd_status(int status)
{
	t_app	*app;
	char	*number;

	app = app_instance();
	number = ft_itoa(status);
	if (number == NULL)
		exit_errorc(STR_APPNAME, ERRC_NOT_ENOUGH_MEMORY, 1, app_destroy);
	env_set(&app->vars, "$?", number);
	if (number)
		free(number);
}
