/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:22:48 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:39:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "parser_matrix.h"
#include "parser_mat_row.h"
#include "parser_mat_row_kv.h"
#include <ft_error.h>
#include <stdlib.h>

void	parser_mat_init(t_parser_mat *mat)
{
	btree_init(&mat->rows, free, parser_mat_row_cmp);
}

void	parser_mat_destroy(t_parser_mat *mat)
{
	btree_prefix(&mat->rows, parser_mat_row_destroy);
	btree_destroy(&mat->rows);
}

void	parser_mat_clear(t_parser_mat *mat)
{
	btree_prefix(&mat->rows, parser_mat_row_destroy);
	btree_clear(&mat->rows);
}

void	parser_mat_set(t_parser_mat *mat,
						t_ui current,
						t_mat_row_kv const *state)
{
	t_btree_node			*node;
	t_parser_mat_row		kv;
	t_parser_mat_row		*temp;

	kv.row_id = current;
	node = btree_find(&mat->rows, &kv);
	if (node)
		temp = (t_parser_mat_row *)node->value;
	else
	{
		temp = (t_parser_mat_row *)malloc(sizeof(*temp));
		parser_mat_row_init(temp, current);
	}
	if (temp == NULL)
		exit_errorc(STR_APPNAME, ERRC_NOT_ENOUGH_MEMORY, 1, app_destroy);
	if (node == NULL)
		btree_insert(&mat->rows, temp);
	parser_mat_row_set(temp, state);
}
