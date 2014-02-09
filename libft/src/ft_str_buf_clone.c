/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_clone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 15:38:44 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 15:42:32 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include "ft_memory.h"

void	str_buf_clone(t_str_buf *clone, t_str_buf const *strbuf)
{
	str_buf_clear(clone);
	str_buf_app_strn(clone, strbuf->buffer, strbuf->size);	
}
