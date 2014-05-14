/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mat_row_kv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 18:24:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:02:23 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_mat_row_kv.h"
#include <ft_memory.h>

void	mat_row_kv_init(t_mat_row_kv *kv, char key, t_ui value, t_bool final)
{
	kv->key = key;
	kv->value = value;
	kv->final = final;
}

void	mat_row_kv_destroy(t_mat_row_kv *kv)
{
	if (kv)
		ft_bzero(kv, sizeof(*kv));
}

int		mat_row_kv_cmp(t_mat_row_kv const *left, t_mat_row_kv const *right)
{
	if (left->key > right->key)
		return (1);
	else if (left->key < right->key)
		return (-1);
	else
		return (0);
}
