/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:38:40 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 00:54:13 by irabeson         ###   ########.fr       */
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
#include <stdio.h>
void	parser_run(t_parser *parser, char const *str, t_list *lexems)
{
	char const	*it;
	t_ui		current;
	t_ui		next;
	t_lexem		lexem;
	t_bool		final;

	it = str;
	current = parser->init_state;
	next = PARSER_ERR_STATE;
	lexem.size = 0;
	lexem.str = NULL;
	while (*it != '\0')
	{
		final = parser_mat_is_final(&parser->matrix, current, *it);
		current = parser_mat_get(&parser->matrix, current, *it);
		if (current == PARSER_ERR_STATE)
		{
			ft_putendl("et merde...");
			break ;
		}
		next = parser_mat_get(&parser->matrix, current, *(it + 1));
		if (lexem.str == NULL)
		{
			lexem.str = (char *)it;
			lexem.size = 1;
		}
		if (current != next && final)
		{
			lexem.state_id = current;
			printf("push '%.*s' state %u\n", lexem.size, lexem.str, current);
			list_push_back(lexems, (void *)lexem_clone(&lexem));
			lexem.str = NULL;
			lexem.size = 0;
			current = parser->init_state;
		}
		else
			++lexem.size;
		++it;
	}
}
