/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_imp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 01:59:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 12:46:08 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexem.h"
#include "lexems.h"
#include "cmd.h"
#include "app.h"
#include "syntax.h"
#include <ft_list.h>
#include <ft_list_node.h>

t_bool	build_redirects_in(t_cmd *cmd, t_list *cmd_lexems)
{
	t_list_node	*lex_it;
	t_lexem		*lex;

	lex_it = lexems_find_next(cmd_lexems->first, ST_OP_REDIR_IN);
	if (lex_it)
	{
		lex_it = list_erase(cmd_lexems, lex_it);
		if (lex_it == NULL || lex_it->item == NULL)
			return (false);
		lex = (t_lexem *)lex_it->item;
		if (!lexem_type_is(lex, ST_PARAM) && !lexem_type_is(lex, ST_FPARAM))
			return (false);
		cmd_set_in_file(cmd, lex->str);
		lex_it = list_erase(cmd_lexems, lex_it);
	}
	return (true);
}

t_bool	build_redirects_out(t_cmd *cmd, t_list *cmd_lexems)
{
	t_list_node	*lex_it;
	t_lexem		*lex;

	lex_it = lexems_find_next(cmd_lexems->first, ST_OP_REDIR_OUT);
	if (lex_it)
	{
		if (cmd->next)
			return (false);
		lex_it = list_erase(cmd_lexems, lex_it);
		if (lex_it == NULL || lex_it->item == NULL)
			return (false);
		lex = (t_lexem *)lex_it->item;
		if (!lexem_type_is(lex, ST_PARAM) && !lexem_type_is(lex, ST_FPARAM))
			return (false);
		cmd_set_out_file(cmd, lex->str, true);
		lex_it = list_erase(cmd_lexems, lex_it);
	}
	return (true);
}

t_bool	build_redirects_outa(t_cmd *cmd, t_list *cmd_lexems)
{
	t_list_node	*lex_it;
	t_lexem		*lex;

	lex_it = lexems_find_next(cmd_lexems->first, ST_OP_REDIR_OUTA);
	if (lex_it)
	{
		if (cmd->next)
			return (false);
		lex_it = list_erase(cmd_lexems, lex_it);
		if (lex_it == NULL || lex_it->item == NULL)
			return (false);
		lex = (t_lexem *)lex_it->item;
		if (!lexem_type_is(lex, ST_PARAM) && !lexem_type_is(lex, ST_FPARAM))
			return (false);
		cmd_set_out_file(cmd, lex->str, false);
		lex_it = list_erase(cmd_lexems, lex_it);
	}
	return (true);
}

t_bool	build_pipes(t_cmd *cmd, t_list *cmd_lexems)
{
	t_list_node	*lex_it;

	lex_it = lexems_find_next(cmd_lexems->first, ST_OP_PIPE);
	if (lex_it)
	{
		if (cmd->next || cmd->out_file)
			return (false);
		lex_it = list_erase(cmd_lexems, lex_it);
		if (lex_it == NULL)
			return (false);
		cmd->next = cmd_malloc();
		return (build_cmd(cmd->next, cmd_lexems));
	}
	return (true);
}

void	build_args(t_cmd *cmd, t_list *cmd_lexems)
{
	t_list_node	*it;
	t_lexem		*lex;

	it = cmd_lexems->first;
	while (it && it->item)
	{
		lex = (t_lexem *)it->item;
		if (lex->state_id == ST_OP_PIPE
			|| lex->state_id == ST_OP_REDIR_IN
			|| lex->state_id == ST_OP_REDIR_OUT
			|| lex->state_id == ST_OP_REDIR_OUTA)
			break ;
		cmd_add_arg(cmd, lex->str);
		it = list_erase(cmd_lexems, it);
	}
}
