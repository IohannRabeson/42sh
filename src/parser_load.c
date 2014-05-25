/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 03:28:08 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 18:28:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser_load(t_parser *parser, t_parser_trans const *trans)
{
	if (trans == NULL)
		return ;
	while (trans->chars)
	{
		parser_add_chars(parser, trans->current, trans->next, trans->chars);
		++trans;
	}
}
