/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:58:51 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 04:56:24 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexem.h"
# include "parser_matrix.h"
# include <ft_types_def.h>
# include <ft_list.h>
# include <stdlib.h>

struct			s_mat_row_kv;

typedef	struct	s_parser_run_imp
{
	char const	*it;
	t_ui		current;
	t_ui		next;
	t_lexem		lexem;
	t_bool		final;
	t_ui		pos;
	t_bool		error;
}				t_parser_run_imp;

typedef struct	s_parser
{
	t_parser_mat	matrix;
	t_ui			init_state;
	t_ui			free_id;
	t_bool			verbose;
}				t_parser;

typedef enum	s_trans_type
{
	PTT_CHARS,
	PTT_KEYWORD,
	PTT_NULL
}				t_trans_type;

typedef struct	s_parser_trans
{
	t_trans_type	type;
	t_ui			current;
	t_ui			next;
	char const		*chars;
}					t_parser_trans;

void	parser_init(t_parser *parser, t_ui init_state);
void	parser_load(t_parser *parser, t_parser_trans const *trans);
void	parser_destroy(t_parser *parser);
void	parser_clear(t_parser *parser);
t_bool	parser_run(t_parser *parser, char const *str, t_list *lexems);

/*
**	Add a transition.
*/
void		parser_add(t_parser *parser,
					   t_ui start,
					   struct s_mat_row_kv const *state);

/*
**	Add a keyword to the parser.
**	
**	A keyword is a chain of state.<br/>
**	The last state define the keyword id when the parser parses it.
*/
void	parser_add_keyword(t_parser *parser,
						   t_ui start,
						   t_ui keyword_id,
						   char const *str);

/*
**
**
*/
void	parser_add_chars(t_parser *parser,
						 t_ui start,
						 t_ui keyword_id,
						 char const *str);

#endif
