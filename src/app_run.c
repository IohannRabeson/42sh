/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:11:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:08:46 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "cmd.h"
#include <ft_string.h>
#include <stdlib.h>

static t_lexem		*app_get_lex(t_list_node const *lex_it)
{
	t_lexem	*lex;

	lex = NULL;
	if (lex_it)
		lex = (t_lexem *)lex_it->item;
	return (lex);
}

static t_bool		app_skip_lexs(t_list_node const *lex_it)
{
	t_lexem const * const	lex = app_get_lex(lex_it);

	return (lex && lex->state_id != ST_PARAM
				&& lex->state_id != ST_FPARAM);
}

static t_list_node	*app_extract_cmd(t_list_node *lex_it, t_cmd *cmd)
{
	t_app * const	app = app_instance();
	t_lexem			*lex;
	t_list			params;

	list_init(&params, free);
	while (lex_it && app_skip_lexs(lex_it) && lex_it->item)
	{
		lex = app_get_lex(lex_it);
		list_push_back(&params, (void *)ft_strndup(lex->str, lex->size));
		lex_it = lex_it->next;
	}
	cmd_setup(cmd, &params, app);
	list_destroy(&params);
	if (lex_it)
		return (lex_it->next);
	return (lex_it);
}

static t_list_node	*app_process_cmd(t_list *lexems)
{
	t_app * const	app = app_instance();
	t_cmd			cmd;
	t_list_node		*lex_it;

	lex_it = list_first(lexems);
	cmd_init(&cmd);
	lex_it = app_extract_cmd(lex_it, &cmd);
	cmd_exec(&cmd, &app->env);
	cmd_destroy(&cmd);
	return (lex_it);
}

t_bool				app_run(void)
{
	t_app * const	app = app_instance();
	t_list			lexems;
	char			*line;

	line = NULL;
	list_init(&lexems, free);
	if (app->run == false)
		return (false);
	line = app_readline();
	if (line && ft_strlen(line) > 0 && parser_run(&app->parser, line, &lexems))
	{
		app_process_cmd(&lexems);
		list_foreach(&lexems, lexem_put);
		list_clear(&lexems);
	}
	else
		app_stop();
	if (line)
		free(line);
	list_destroy(&lexems);
	return (true);
}
