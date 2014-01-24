/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:38:40 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 03:23:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <ft_memory.h>
#include <ft_minmax.h>
#include <ft_string.h>
#include <ft_print.h>
#include <unistd.h>

#include <ft_error.h>

void		parser_init(t_parser *parser, t_ui init_state)
{
	parser_mat_init(&parser->matrix);
	parser->init_state = init_state;
	parser->free_id = PARSER_ERR_STATE - 1;
}

void		parser_destroy(t_parser *parser)
{
	parser_mat_destroy(&parser->matrix);
	parser->init_state = PARSER_ERR_STATE;
	parser->free_id = 0;
}

void		parser_clear(t_parser *parser)
{
	parser_mat_clear(&parser->matrix);
}
