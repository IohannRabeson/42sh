/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder_setup_params.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:01:48 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 21:00:48 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_builder.h"
#include "path.h"
#include "cmd.h"
#include "app.h"
#include "app_lexems.h"
#include "builtins.h"
#include "builtin.h"
#include "env.h"
#include "lexem.h"
#include <ft_string.h>
#include <ft_list.h>
#include <ft_str_array.h>
#include <stdlib.h>

static char			*cmd_resolve_exec_path(char const *exec_path)
{
	t_app	* const	app = app_instance();
	char			**paths;
	char			**path_it;
	char			*complete_path;

	paths = ft_strsplit(env_get_value(&app->env, "PATH"), ':');
	if (paths == NULL)
		return (NULL);
	path_it = paths;
	while (path_it && *path_it)
	{
		complete_path = path_concat(*path_it, exec_path);
		if (path_exists(complete_path) && path_is_executable(complete_path))
			return (complete_path);
		if (complete_path)	
			free(complete_path);
		++path_it;
	}
	str_array_free(paths);
	return (NULL);
}

static t_bool		builtins_contains(char const *exec_path)
{
	t_app	* const	app = app_instance();
	t_builtin		*bt;

	bt = builtins_find(&app->builtins, exec_path);
	return (bt != NULL);
}

static void			setup_cmd_type(t_cmd *cmd)
{
	char	*exec_path;
	char	*resolved_path;

	exec_path = cmd->params[0];
	if (builtins_contains(exec_path))
	{
		cmd->type = CMD_BUILTIN;
	}
	else
	if (path_is_executable(exec_path))
	{
		cmd->type = CMD_EXE;
	}
	else
	{
		resolved_path = cmd_resolve_exec_path(exec_path);
		if (resolved_path)
		{
			free(cmd->params[0]);
			cmd->params[0] = resolved_path;
			cmd->type = CMD_EXE;
		}
		else
			cmd->type = CMD_UNKNOW;
	}
}

t_list_node			*cmd_bld_setup_params(t_cmd *cmd, t_list_node *lex_it)
{
	t_lexem	*lex;
	char	*temp;

	if (lex_it == NULL)
		return (NULL);
	lex = (t_lexem *)lex_it->item;
	while (lex_it && (lexem_is_params(lex)
						|| lexem_type_is(lex, ST_DELIM_PARAM_IN)
						|| lexem_type_is(lex, ST_DELIM_PARAM_OUT)))
	{
		if (lexem_is_params(lex))
		{
			temp = lexem_get_text(lex);
			cmd->params = str_array_append(cmd->params, temp);
			free(temp);
			if (str_array_size(cmd->params) == 1)
				setup_cmd_type(cmd);
		}
		lex_it = lex_it->next;
		if (lex_it != NULL)
			lex = (t_lexem *)lex_it->item;
	}
	cmd->params_count = str_array_size(cmd->params);
	return (lex_it);
}
