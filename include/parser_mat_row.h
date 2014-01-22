/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mat_row.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 18:30:53 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 23:50:10 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MAT_ROW_H
# define PARSER_MAT_ROW_H
# include <ft_btree.h>
# include <ft_types_def.h>

struct			s_mat_row_kv;

typedef struct	s_parser_mat_row
{
	t_ui	row_id;
	t_btree	cols;
}				t_parser_mat_row;

void	parser_mat_row_init(t_parser_mat_row *row, t_ui row_id);
void	parser_mat_row_destroy(t_parser_mat_row *row);
void	parser_mat_row_clear(t_parser_mat_row *row);
t_ui	parser_mat_row_get(t_parser_mat_row const *row, char col_id);
t_bool	parser_mat_row_is_final(t_parser_mat_row const *row, char col_id);
t_bool	parser_mat_row_set(t_parser_mat_row *row,
						   struct s_mat_row_kv const *value);
int		parser_mat_row_cmp(t_parser_mat_row const *left,
						   t_parser_mat_row const *right);
#endif
