/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mat_row_kv.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 18:33:08 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 22:55:41 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MAT_ROW_KV_H
# define PARSER_MAT_ROW_KV_H
# include <ft_types_def.h>

typedef struct	s_mat_row_kv
{
	char	key;
	t_ui	value;
	t_bool	final;
}				t_mat_row_kv;

void	mat_row_kv_init(t_mat_row_kv *kv, char key, t_ui value, t_bool final);
void	mat_row_kv_destroy(t_mat_row_kv *kv);
int		mat_row_kv_cmp(t_mat_row_kv const *left, t_mat_row_kv const *right);

#endif
