/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add_kw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 21:46:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/19 04:48:30 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_matrix.h"
#include "parser_mat_row_kv.h"
#include <ft_string.h>

static void		parser_addc(t_parser *parser,
							t_ui start,
							t_ui next,
							char c)
{
	t_mat_row_kv	kv;

	kv.key = c;
	kv.value = next;
	kv.final = false;
	parser_add(parser, start, &kv);
}

static t_ui		parser_consume_free_id(t_parser *parser)
{
	return (parser->free_id--);
}

static t_ui		parser_add_kw_imp(t_parser *parser,
								   t_ui start,
								   char const *str)
{
	const size_t	str_size = ft_strlen(str);
	size_t			i;
	t_ui			auto_id;
	t_ui			last_id;

	i = 0;
	last_id = start;
	while (*str != '\0' && i < str_size - 1)
	{
		auto_id = parser_mat_get(&parser->matrix, last_id, *str);
		if (auto_id == PARSER_ERR_STATE)
			auto_id = parser_consume_free_id(parser);
		if (auto_id == PARSER_ERR_STATE)
		{
			break ;
		}
		parser_addc(parser, last_id, auto_id, *str);
		last_id = auto_id;
		++str;
		++i;
	}
	return (last_id);
}

void			parser_add_keyword(t_parser *parser,
								   t_ui start,
								   t_ui next,
								   char const *str)
{
	const size_t	str_size = ft_strlen(str);
	t_ui			last_id;
	t_mat_row_kv	kv;

	if (str_size == 0)
	{
		return ;
	}
	else if (str_size == 1)
	{
		kv.key = *str;
		kv.value = next;
		kv.final = true;
		parser_add(parser, start, &kv);
		return ;
	}
	last_id = parser_add_kw_imp(parser, start, str);
	if (*str != '\0')
	{
		kv.key = *str;
		kv.value = next;
		kv.final = true;
		parser_add(parser, last_id, &kv);
	}
}
