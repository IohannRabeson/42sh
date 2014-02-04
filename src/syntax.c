/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:58:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 01:04:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

void	extract_cmd(t_list *src, t_list *cmd_lexems)
{
	t_list_node	*it;
	t_lexem		*lex;
	t_lexem		*new_lex;

	it = list_first(src);
	while (it && it->item)
	{
		lex = (t_lexem *)it->item;
		if (lex->state_id == ST_END_CMD)
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
