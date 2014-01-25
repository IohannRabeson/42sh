/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:11:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:22:21 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "cmd.h"
#include "lexem.h"
#include "cmd_builder.h"
#include <ft_string.h>
#include <ft_print.h>
#include <stdlib.h>
#include <unistd.h>

t_bool				app_run(void)
{
	t_app * const	app = app_instance();
	char			*line;

	line = NULL;
	if (app->run == false)
		return (false);
	line = app_readline();
	app_process_line(line);
	if (line)
		free(line);
	return (true);
}
