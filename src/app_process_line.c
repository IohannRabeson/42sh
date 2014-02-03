/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_process_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:22:41 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/03 20:30:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "app_lexems.h"
#include "lexem.h"
#include "lexems.h"
#include "cmd.h"
#include <ft_print.h>
#include <ft_list.h>
#include <ft_string.h>


void				app_process_lexems(t_list *lexems)
{
	lexems_preprocess(lexems);
}

t_bool				app_process_line(char const *line)
{
	t_app * const	app = app_instance();
	t_list			lexems;
	
	list_init(&lexems, free);
	if (line && ft_strlen(line) > 0 && parser_run(&app->parser, line, &lexems))
	{
		app_process_lexems(&lexems);
		list_clear(&lexems);
		return (true);
	}
	list_destroy(&lexems);
	return (false);
}
