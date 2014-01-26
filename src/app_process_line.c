/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_process_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:22:41 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 21:07:50 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "app_lexems.h"
#include "lexem.h"
#include "cmd.h"
#include "cmd_builder.h"
#include <ft_print.h>
#include <ft_list.h>
#include <ft_string.h>

static t_list_node	*app_process_all_cmd(t_list *lexems)
{
	t_app * const	app = app_instance();
	t_cmd			cmd;
	t_list_node		*lex_it;

	lex_it = list_first(lexems);
	while (lex_it)
	{
		cmd_init(&cmd);
		lex_it = cmd_bld_build(&cmd, lex_it);
		if (cmd_is_builtin(&cmd))
			cmd_exec_builtin(&cmd, &app->env);
		else if (cmd_is_exec(&cmd))
			cmd_exec(&cmd, &app->env);
		else
			cmd_errorl(&cmd, 1, "unknow command");
		cmd_destroy(&cmd);
	}
	return (lex_it);
}

static t_bool		lexem_is_spaces(t_lexem *lex)
{
	return (lexem_type_is(lex, ST_SKIP_SPACES));
}

t_bool				app_process_line(char const *line)
{
	t_app * const	app = app_instance();
	t_list			lexems;
	
	list_init(&lexems, free);
	if (line && ft_strlen(line) > 0 && parser_run(&app->parser, line, &lexems))
	{
		list_erase_if(&lexems, lexem_is_spaces);
		app_process_all_cmd(&lexems);
		list_clear(&lexems);
		return (true);
	}
	list_destroy(&lexems);
	return (false);
}
