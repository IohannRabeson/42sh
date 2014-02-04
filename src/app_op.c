/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:08:06 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 02:53:33 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "parser.h"
#include <ft_print.h>
#include <ft_string.h>
#include <unistd.h>

char	*app_readline(void)
{
	t_app * const	app = app_instance();
	int				gnl_res;
	char			*line;

	ft_putstr(STR_PROMPT);
	line = NULL;
	gnl_res = get_next_line(&app->gnl, &line, STDIN_FILENO);
	if (gnl_res > 0)
	{
		if (line && ft_strlen(line) > 0)
			return (line);
	}
	else if (gnl_res == 0)
	{
		app_stop();
	}
	else
	{
		ft_putendl_fd("ft_sh: unable to reading from stdin", STDERR_FILENO);
		app_stop();
	}
	if (line)
		free(line);
	return (NULL);
}
