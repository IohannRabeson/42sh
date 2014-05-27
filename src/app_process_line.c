/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_process_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:22:41 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/27 03:20:05 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "app_lexems.h"
#include "lexem.h"
#include "lexems.h"
#include "syntax.h"
#include "cmd.h"
#include <ft_print.h>
#include <ft_list.h>
#include <ft_string.h>
#include <ft_str_array.h>
#include <unistd.h>

void				app_exec_cmds(t_list *cmds)
{
	t_app		*app;
	t_list_node	*it;
	t_cmd		*cmd;

	app = app_instance();
	it = cmds->first;
	while (it)
	{
		cmd = (t_cmd *)it->item;
		app_process_cmd(cmd, &app->env);
		if (cmd->condition != NULL
			&& cmd->condition(cmd->exit_code) == false)
		{
			it = list_erase(cmds, it);
			if (it)
				it = list_erase(cmds, it);
		}
		else
			it = list_erase(cmds, it);
	}
}

static void			app_extract_cmds(t_list *lexems,
										t_list *cmd_lexems,
										t_list *cmds)
{
	t_cmd	*cmd;

	while (!list_empty(lexems))
	{
		cmd = cmd_malloc();
		cmd_init(cmd);
		extract_cmd(lexems, cmd_lexems, cmd);
		if (build_cmd(cmd, cmd_lexems) == false)
		{
			ft_putendl_fd("ft_sh: invalid command line", STDERR_FILENO);
			cmd_free(cmd);
			break ;
		}
		else
			list_push_back(cmds, cmd);
		list_clear(cmd_lexems);
	}
}

void				app_process_lexems(t_list *lexems)
{
	t_list	cmds;
	t_list	cmd_lexems;

	list_init(&cmds, cmd_free);
	list_init(&cmd_lexems, lexem_free);
	lexems_preprocess(lexems);
	if (app_instance()->parser.verbose)
		list_foreach(lexems, lexem_put);
	app_extract_cmds(lexems, &cmd_lexems, &cmds);
	app_exec_cmds(&cmds);
	list_destroy(&cmds);
	list_destroy(&cmd_lexems);
}

t_bool				app_process_line(char const *line)
{
	t_app	*app;
	t_list	lexems;

	app = app_instance();
	list_init(&lexems, lexem_free);
	if (line && ft_strlen(line) > 0 && parser_run(&app->parser, line, &lexems))
	{
		app_process_lexems(&lexems);
		return (true);
	}
	list_destroy(&lexems);
	return (false);
}
