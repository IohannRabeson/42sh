/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 01:31:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 02:08:22 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_builder.h"
#include "lexem.h"
#include "app.h"
#include "cmd.h"
#include <ft_str_array.h>
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
			filename = lexem_get_text(next_lex);
			cmd->fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 644);
			lex_it = lex_it->next;
		}
		else if (lexem_type_is(lex, ST_OP_REDIR_OUTA))
		{
			filename = lexem_get_text(next_lex);
			cmd->fd_out = open(filename, O_WRONLY | O_CREAT, 644);
			lex_it = lex_it->next;
		}
		if (filename)
			free(filename);
	}
	return (lex_it);
}

static t_list_node	*parser_params(t_cmd *cmd, t_list_node *lex_it)
{
	t_lexem	*lex;
	
	if (lex_it == NULL)
		return (NULL);
	lex = (t_lexem *)lex_it->item;
	while (lexem_is_params(lex))
	{
		cmd->params = str_array_append(cmd->params,
										lexem_get_text(lex));
		lex_it = lex_it->next;
		lex = (t_lexem *)lex_it->item;
	}
	return (lex_it);
}

t_list_node	*cmd_bld_build(t_cmd_bld *builder, t_cmd *cmd, t_list_node *lex_it)
{
	if (lex_it == NULL)
		return (NULL);
	lex_it = parser_params(cmd, lex_it);
	if (lex_it == NULL)
		return (NULL);
	lex_it = parser_operators(cmd, lex_it);
	return (lex_it);
	(void)builder;
}
