/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 23:10:31 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 00:18:05 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include "cmd.h"
#include "lexems.h"
#include "app.h"

static t_bool	build_redirects_in(t_cmd *cmd, t_list *cmd_lexems)
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

static t_bool	build_redirects_out(t_cmd *cmd, t_list *cmd_lexems)
{
	t_list_node	*lex_it;
	t_lexem		*lex;

	lex_it = lexems_find_next(cmd_lexems->first, ST_OP_REDIR_OUT);
	if (lex_it)
	{
		lex_it = list_erase(cmd_lexems, lex_it);
		if (lex_it == NULL || lex_it->item == NULL)
			return (false);
		lex = (t_lexem *)lex_it->item;
		if (!lexem_type_is(lex, ST_PARAM) && !lexem_type_is(lex, ST_FPARAM))
			return (false);
		cmd_set_out_file(cmd, lex->str, true);
		lex_it = list_erase(cmd_lexems, lex_it);
	}
	lex_it = lexems_find_next(cmd_lexems->first, ST_OP_REDIR_OUTA);
	if (lex_it)
	{
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

static t_bool	build_pipes(t_cmd *cmd, t_list *cmd_lexems)
{
	t_list_node	*lex_it;

	lex_it = lexems_find_next(cmd_lexems->first, ST_OP_PIPE);
	if (lex_it)
	{
		lex_it = list_erase(cmd_lexems, lex_it);
		if (lex_it == NULL)
			return (false);
		cmd->next = cmd_malloc();
		return (build_cmd(cmd->next, cmd_lexems));
	}
	return (true);
}

static void	build_args(t_cmd *cmd, t_list *cmd_lexems)
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

t_bool		build_cmd(t_cmd *cmd, t_list *cmd_lexems)
{
	if (build_redirects_in(cmd, cmd_lexems) == false)
		return (false);
	build_args(cmd, cmd_lexems);
	if (build_pipes(cmd, cmd_lexems) == false)
		return (false);
	if (build_redirects_out(cmd, cmd_lexems) == false)
		return (false);
	return (true);
}
