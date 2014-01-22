/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:38:40 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/23 00:18:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <ft_memory.h>
#include <ft_minmax.h>
#include <ft_string.h>
#include <ft_print.h>
#include <unistd.h>

#include <ft_error.h>

void	parser_init(t_parser *parser, t_ui init_state)
{
	parser_mat_init(&parser->matrix);
	parser->init_state = init_state;
	parser->free_id = PARSER_ERR_STATE - 1;
}

void	parser_destroy(t_parser *parser)
{
	parser_mat_destroy(&parser->matrix);
	parser->init_state = PARSER_ERR_STATE;
	parser->free_id = 0;
}

void	parser_clear(t_parser *parser)
{
	parser_mat_clear(&parser->matrix);
}

void	parser_run(t_parser *parser, char const *str, t_list *lexems)
{
	char const	*it;
	char const	*lex_start;
	t_ui		size;
	t_ui		current;
	t_ui		last;
	t_lexem		*lexem;

	if (str == NULL || ft_strlen(str) == 0)
		return ;
	current = parser->init_state;
	it = str;
	lex_start = it;
	size = 0;
	while (*it)
	{
		last = current;
		current = parser_mat_get(&parser->matrix, last, *it);
		if (current == PARSER_ERR_STATE)
			exit_errorm("Fuck");
		if (last != parser->init_state && last != current
				&& parser_mat_is_final(&parser->matrix, current, *it))
		{
			lexem = lexem_malloc();
			lexem_set(lexem, current, lex_start, size);
			list_push_back(lexems, (void *)lexem_clone(lexem));
			lex_start = it;
			size = 0;
		}
		else
			++size;
		++it;
	}
	lexem = lexem_malloc();
	lexem_set(lexem, current, lex_start, size);
	list_push_back(lexems, (void *)lexem_clone(lexem));
}
