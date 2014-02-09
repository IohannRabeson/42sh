/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 20:22:46 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 21:46:14 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_matrix.h"
#include "parser_mat_row_kv.h"
#include <ft_string.h>

void			parser_add(t_parser *parser,
						   t_ui start,
						   t_mat_row_kv const *state)
{
	parser_mat_set(&parser->matrix, start, state);
}

void	parser_add_chars(t_parser *parser,
						 t_ui start,
						 t_ui next,
						 char const *str)
{
	t_mat_row_kv	kv;

	if (str == NULL)
		return ;
	kv.value = next;
	while (*str != '\0')
	{
		kv.key = *str;
		kv.final = true;
		parser_add(parser, start, &kv);
		++str;
	}
}
