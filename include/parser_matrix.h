/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_matrix.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:42:27 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 19:40:23 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MATRIX_H
# define PARSER_MATRIX_H
# define PARSER_MAX_STATE	1000000
# define PARSER_ERR_STATE	PARSER_MAX_STATE
# include <ft_types_def.h>
# include <ft_btree.h>

struct s_mat_row_kv;

typedef struct	s_parser_mat
{
	t_btree rows;
}				t_parser_mat;

void			parser_mat_init(t_parser_mat *mat);
void			parser_mat_destroy(t_parser_mat *mat);
void			parser_mat_clear(t_parser_mat *mat);
t_ui			parser_mat_get(t_parser_mat *mat, t_ui current, char c);
t_bool			parser_mat_is_final(t_parser_mat *mat, t_ui current, char c);
void			parser_mat_set(t_parser_mat *mat, t_ui current,
								struct s_mat_row_kv const *state);

#endif
