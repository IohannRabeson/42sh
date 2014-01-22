/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:16:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/23 00:20:33 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "parser.h"
#include "parser_mat_row.h"
#include <ft_get_next_line.h>
#include <ft_list.h>
#include <ft_print.h>
#include <ft_string.h>
#include <unistd.h>
#include <stdio.h>

void	put_lexem(t_lexem const *lex)
{
	ft_putui(lex->state_id);
	ft_putstr(" - ");
	ft_putstrn(lex->str, lex->size);
	ft_putchar('\n');
}

void	test_mat_row(t_parser_mat_row *mat_row, char c)
{
	printf("%c: %d\n", c, parser_mat_row_get(mat_row, c));
}

int	main(int argc, char **argv, char **environs)
{
	t_gnl		gnl;
	t_parser	parser;
	t_list		lexems;
	char		*line;

	t_btree	tree;
	btree_init(&tree, free, ft_strcmp);
	line = NULL;
	gnl_init(&gnl);
	app_init(argc, argv, environs);
	parser_init(&parser, 0);
	parser_add_keyword(&parser, 0, 1, "hello");
	parser_add_keyword(&parser, 0, 2, "world");
	parser_add_keyword(&parser, 0, 3, "wally");
	parser_add_keyword(&parser, 0, 4, "hellihello");
	list_init(&lexems, free);
	while (get_next_line(&gnl, &line, STDIN_FILENO) > 0)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		btree_insert(&tree, line);
		parser_run(&parser, line, &lexems);
		list_foreach(&lexems, put_lexem);
		list_clear(&lexems);
	}
	btree_infix(&tree, ft_putendl);
	btree_destroy(&tree);
	list_destroy(&lexems);
	parser_destroy(&parser);
	app_destroy();
	gnl_destroy(&gnl);
	return (0);
}
