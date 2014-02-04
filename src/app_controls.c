/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:07:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 02:51:38 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	app_stop(void)
{
	t_app * const	app = app_instance();

	app->run = false;
	app->exit_code = 0;
}

void	app_exit(int code)
{
	t_app * const	app = app_instance();

	app->run = false;
	app->exit_code = code;
}
