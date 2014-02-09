/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:58:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 15:59:57 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"

void	str_buf_pop_front(t_str_buf *strbuf)
{
	str_buf_erase(strbuf, 0, 1);
}

void	str_buf_pop_back(t_str_buf *strbuf)
{
	if (strbuf->size > 0)
		--strbuf->size;
}
