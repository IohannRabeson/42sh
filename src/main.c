/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:16:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 01:48:06 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <signal.h>
#include <ft_print.h>

void	signal_handler(int sig)
{
	t_app const * const	app = app_instance();
	if (sig == SIGINT)
	{
		if (app->current_cmd)
			ft_putchar('\n');
		app_kill_cmd(sig);
	}
	else
	{
		ft_putchar('\n');
		kill(0, sig);
	}
}

int	main(int argc, char **argv, char **environs)
{
	int	ec;

	signal(SIGINT, signal_handler);
	app_init(argc, argv, environs);
	while (app_run())
	{
	}
	ec = app_instance()->exit_code;
	app_destroy();
	return (ec);
}
