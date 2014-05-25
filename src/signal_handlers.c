/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 00:22:03 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/24 00:25:00 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handlers.h"
#include "app.h"
#include <signal.h>
#include <ft_print.h>

void	signal_handler(int sig)
{
	t_app const *const	app = app_instance();

	if (sig == SIGINT)
	{
		if (app->current_cmd)
			ft_putchar('\n');
		app_kill_cmd(sig);
	}
	else
	{
		//ft_putchar('\n');
		kill(0, sig);
	}
}

