/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mat_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:53:04 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/16 15:42:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "parser_matrix.h"
#include "parser_mat_row.h"
#include "parser_mat_row_kv.h"
#include <ft_error.h>
#include <stdlib.h>

void	parser_mat_row_init(t_parser_mat_row *row, t_ui row_id)
{
	btree_init(&row->cols, free, mat_row_kv_cmp);
	row->row_id = row_id;
}

void	parser_mat_row_destroy(t_parser_mat_row *row)
{
	btree_destroy(&row->cols);
}

void	parser_mat_row_clear(t_parser_mat_row *row)
{
	btree_prefix(&row->cols, mat_row_kv_destroy);
	btree_clear(&row->cols);
}

t_bool	parser_mat_row_set(t_parser_mat_row *row,
							t_mat_row_kv const *value)
{
	t_btree_node	*node;
	t_mat_row_kv	*temp;
	t_bool			result;

	node = btree_find(&row->cols, (void *)value);
	result = node == NULL;
	if (node)
		temp = (t_mat_row_kv *)node->value;
	else
		temp = (t_mat_row_kv *)malloc(sizeof(*temp));
	if (temp == NULL)
		exit_errorc(STR_APPNAME, ERRC_NOT_ENOUGH_MEMORY, 1, app_destroy);
	temp->key = value->key;
	temp->value = value->value;
	temp->final = value->final;
	if (node == NULL && temp)
		btree_insert(&row->cols, temp);
	return (result);
}

int		parser_mat_row_cmp(t_parser_mat_row const *left,
							t_parser_mat_row const *right)
{
	if (left->row_id < right->row_id)
		return (-1);
	else if (left->row_id > right->row_id)
		return (1);
	else
		return (0);
}
