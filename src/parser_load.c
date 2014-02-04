/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 03:28:08 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 03:22:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser_load(t_parser *parser, t_parser_trans const *trans)
{
	if (trans == NULL)
		return ;
	while (trans->chars)
	{
		if (trans->type == PTT_CHARS)
		{
			parser_add_chars(parser, trans->current,
								trans->next, trans->chars);
		}
		else if (trans->type == PTT_KEYWORD)
		{
			parser_add_keyword(parser, trans->current,
								trans->next, trans->chars);
		}
		++trans;
	}
}
