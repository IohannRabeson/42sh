/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:16:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/24 00:23:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "signal_handlers.h"
#include <signal.h>
#include <ft_print.h>

int			main(int argc, char **argv, char **environs)
{
	int	ec;

	if (*environs == NULL)
	{
		ft_putendl_fd("Invalid env", STDERR_FILENO);
		return (0);
	}
	signal(SIGINT, signal_handler);
	app_init(argc, argv, environs);
	while (app_run())
	{
	}
	ec = app_instance()->exit_code;
	app_destroy();
	return (ec);
}
