/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_assign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 02:37:08 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 02:39:22 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"

void			str_buf_assign(t_str_buf *strbuf, char const *str)
{
	str_buf_clear(strbuf);
	str_buf_app_str(strbuf, str);
}
