/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:58:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/27 03:15:44 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static t_bool	condition_and(int exit_code)
{
	return (exit_code == 0);
}

static t_bool	condition_or(int exit_code)
{
	return (exit_code != 0);
}

static t_bool	extract_imp(t_lexem const *lex, t_cmd *cmd)
{
	if (lex->state_id == ST_OP_AND)
	{
		cmd->condition = condition_and;
		return (true);
	}
	if (lex->state_id == ST_OP_OR)
	{
		cmd->condition = condition_or;
		return (true);
	}
	if (lex->state_id == ST_END_CMD)
	{
		return (true);
	}
	return (false);
}

void			extract_cmd(t_list *src, t_list *cmd_lexems, t_cmd *cmd)
{
	t_list_node	*it;
	t_lexem		*lex;
	t_lexem		*new_lex;

	it = list_first(src);
	while (it && it->item)
	{
		lex = (t_lexem *)it->item;
		if (extract_imp(lex, cmd))
		{
			it = list_erase(src, it);
			return ;
		}
		else
		{
			new_lex = lexem_clone(lex);
			list_push_back(cmd_lexems, new_lex);
			it = list_erase(src, it);
		}
	}
}
