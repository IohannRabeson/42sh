/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 01:31:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 05:47:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_builder.h"
#include "lexem.h"
#include "app.h"
#include "cmd.h"
#include "path.h"
#include <ft_str_array.h>
#include <ft_string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static t_bool		lexem_is_params(t_lexem *lex)
{
	return (lexem_type_is(lex, ST_PARAM) || lexem_type_is(lex, ST_FPARAM));
}

static t_bool		lexem_is_operators(t_lexem *lex)
{
	return (lex->state_id == ST_OP_REDIR_OUT
			|| lex->state_id == ST_OP_REDIR_OUTA
			|| lex->state_id == ST_OP_REDIR_IN
			|| lex->state_id == ST_OP_REDIR_INA
			|| lex->state_id == ST_END_CMD);
}

static t_list_node	*parser_operators(t_cmd *cmd, t_list_node *lex_it)
{
	t_lexem	*lex;
	t_lexem	*next_lex;
	char	*filename;

	lex = (t_lexem *)lex_it->item;
	next_lex = NULL;
	filename = NULL;
	if (lexem_is_operators(lex))
	{
		lex_it = lex_it->next;
		if (lex_it)
			next_lex = (t_lexem *)lex_it->item;
		if (lexem_type_is(lex, ST_OP_REDIR_OUT))
		{
			if (lexem_type_is(next_lex, ST_OP_REDIR_OUTA))
			{
				lex_it = lex_it->next;
				next_lex = (t_lexem *)lex_it->item;
				filename = lexem_get_text(next_lex);
				cmd->fd_out = open(filename, O_WRONLY | O_CREAT,
						S_IRUSR | S_IRGRP | S_IWUSR | S_IWGRP);
				cmd->type = (cmd->fd_out != -1) ? CMD_EXE_REDIR_OUT : CMD_ERROR;
			}
			else
			{
				filename = lexem_get_text(next_lex);
				cmd->fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
						S_IRUSR | S_IRGRP | S_IWUSR | S_IWGRP);
				cmd->type = (cmd->fd_out != -1) ? CMD_EXE_REDIR_OUT : CMD_ERROR;
			}
			lex_it = lex_it->next;
		}
		if (filename)
			free(filename);
	}
	return (lex_it);
}

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
		else
			free(complete_path);
		++path_it;
	}
	str_array_free(paths);
	return (NULL);
}

static void			setup_cmd_type(t_cmd *cmd)
{
	char	*exec_path;
	char	*resolved_path;

	exec_path = cmd->params[0];
	///< TODO: verifier ici si c'est pas un builtin
	if (path_is_executable(exec_path))
		cmd->type = CMD_EXE;
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

static t_list_node	*parser_params(t_cmd *cmd, t_list_node *lex_it)
{
	t_lexem	*lex;
	
	if (lex_it == NULL)
		return (NULL);
	lex = (t_lexem *)lex_it->item;
	while (lex_it && (lexem_is_params(lex)
						|| lexem_type_is(lex, ST_DELIM_PARAM_IN)
						|| lexem_type_is(lex, ST_DELIM_PARAM_OUT)))
	{
		if (lexem_is_params(lex))
		{
			cmd->params = str_array_append(cmd->params,
					lexem_get_text(lex));
			if (str_array_size(cmd->params) == 1)
				setup_cmd_type(cmd);
		}
		lex_it = lex_it->next;
		if (lex_it != NULL)
			lex = (t_lexem *)lex_it->item;
	}
	return (lex_it);
}

/*
**	Builds a t_cmd instance with the lexems list.
*/
t_list_node	*cmd_bld_build(t_cmd *cmd, t_list_node *lex_it)
{
	if (lex_it == NULL)
		return (NULL);
	lex_it = parser_params(cmd, lex_it);
	if (lex_it == NULL)
		return (NULL);
	lex_it = parser_operators(cmd, lex_it);
	return (lex_it);
}
