/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 03:23:16 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 22:05:45 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <ft_print.h>

static void	parser_run_lexem_push(t_list *lexems, t_lexem *lexem, t_ui current)
{
	lexem->state_id = current;
	list_push_back(lexems, (void *)lexem_clone(lexem));
	lexem->str = NULL;
	lexem->size = 0;
}

static int	parser_run_check_current(t_parser_run_imp *imp,
									 char const *str)
{
	if (imp->current == PARSER_ERR_STATE)
	{
		ft_putstr("ft_sh: parser: ");
		ft_putstr("unexpected character [");
		ft_putchar(*imp->it);
		ft_putstr("] at ");
		ft_putul(imp->it - str);
		ft_putchar('\n');
		imp->error = true;
		return (1);
	}
	return (0);
}

static void	parser_run_imp_init(t_parser_run_imp *imp,
								t_parser const *parser,
								char const *str)
{
	imp->it = str;
	imp->current = parser->init_state;
	imp->next = PARSER_ERR_STATE;
	imp->lexem.size = 0;
	imp->lexem.str = NULL;
	imp->error = false;
}

static void	parser_run_imp(t_parser_run_imp *imp,
						   t_parser *parser,
						   t_list *lexems,
						   char const *str)
{
	imp->final = parser_mat_is_final(&parser->matrix, imp->current, *imp->it);
	imp->current = parser_mat_get(&parser->matrix, imp->current, *imp->it);
	if (parser_run_check_current(imp, str))
		return ;
	imp->next = parser_mat_get(&parser->matrix, imp->current, *(imp->it + 1));
	if (imp->lexem.str == NULL)
	{
		imp->lexem.str = (char *)imp->it;
		imp->lexem.size = 1;
	}
	if (imp->current != imp->next && imp->final)
		parser_run_lexem_push(lexems, &imp->lexem, imp->current);
	else
		++imp->lexem.size;
}

t_bool		parser_run(t_parser *parser, char const *str, t_list *lexems)
{
	t_parser_run_imp	imp;

	parser_run_imp_init(&imp, parser, str);
	while (*imp.it != '\0')
	{
		parser_run_imp(&imp, parser, lexems, str);
		if (imp.error)
			return (false);
		++imp.it;
	}
	if (!imp.error && !imp.final)
	{
		ft_putendl("manque des trucs mec");
		return (false);
	}
	if (parser->verbose)
		list_foreach(lexems, lexem_put);
	return (true);
}
