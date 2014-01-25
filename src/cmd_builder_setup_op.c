/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder_setup_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:23:44 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 19:25:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_builder.h"
#include "cmd.h"
#include "app.h"
#include "lexem.h"
#include <ft_list.h>

static t_list_node	*setup_cmd_mode(t_cmd *cmd, t_list_node *lex_it)
{
	static const t_cmd_mode	modes_cv[] =
	{
		CMD_MODE_REDIR_OUT,
		CMD_MODE_REDIR_OUTA,
		CMD_MODE_REDIR_IN,
	};
	t_lexem					*lexem;

	if (lex_it == NULL)
		return (NULL);
	lexem = (t_lexem *)lex_it->item;
	if (lexem && lexem->state_id >= ST_OP_REDIR_OUT
		&& lexem->state_id < ST_OP_REDIR_INA)
	{
		cmd->mode = modes_cv[lexem->state_id - ST_OP_REDIR_OUT];
		lex_it = lex_it->next;
	}
	return (lex_it);
}

t_list_node			*cmd_bld_setup_operators(t_cmd *cmd, t_list_node *lex_it)
{
	t_lexem		*operand_lexem;

	if (lex_it == NULL || lex_it->item == NULL)
		return (NULL);
	operand_lexem = NULL;
	lex_it = setup_cmd_mode(cmd, lex_it);
	if (cmd->mode == CMD_MODE_REDIR_OUT)
		lex_it = setup_cmd_mode(cmd, lex_it);
	if (lex_it)
	{
		operand_lexem = (t_lexem *)lex_it->item;
		if (operand_lexem)
		{
			cmd->filename = lexem_get_text(operand_lexem);
			lex_it = lex_it->next;
		}
	}
	return (lex_it);
}
