/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mat_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 21:40:06 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:44:49 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_matrix.h"
#include "parser_mat_row.h"
#include "parser_mat_row_kv.h"

t_ui	parser_mat_get(t_parser_mat *mat, t_ui current, char c)
{
	t_btree_node			*node;
	t_parser_mat_row		kv;
	t_parser_mat_row const	*row;

	kv.row_id = current;
	node = btree_find(&mat->rows, &kv);
	if (node)
	{
		row = (t_parser_mat_row const *)node->value;
		return (parser_mat_row_get(row, c));
	}
	else
		return (PARSER_ERR_STATE);
}

t_bool	parser_mat_is_final(t_parser_mat *mat, t_ui current, char c)
{
	t_btree_node			*node;
	t_parser_mat_row		kv;
	t_parser_mat_row const	*row;

	kv.row_id = current;
	node = btree_find(&mat->rows, &kv);
	if (node)
	{
		row = (t_parser_mat_row const *)node->value;
		return (parser_mat_row_is_final(row, c));
	}
	else
		return (false);
}

t_ui	parser_mat_row_get(t_parser_mat_row const *row, char col_id)
{
	t_btree_node		*node;
	t_mat_row_kv		kv;
	t_mat_row_kv const	*temp;

	mat_row_kv_init(&kv, col_id, PARSER_ERR_STATE, false);
	node = btree_find(&row->cols, &kv);
	if (node && node->value)
	{
		temp = (t_mat_row_kv const *)node->value;
		return (temp->value);
	}
	return (PARSER_ERR_STATE);
}

t_bool	parser_mat_row_is_final(t_parser_mat_row const *row, char col_id)
{
	t_btree_node		*node;
	t_mat_row_kv		kv;
	t_mat_row_kv const	*temp;

	mat_row_kv_init(&kv, col_id, PARSER_ERR_STATE, false);
	node = btree_find(&row->cols, &kv);
	if (node && node->value)
	{
		temp = (t_mat_row_kv const *)node->value;
		return (temp->final);
	}
	return (false);
}

