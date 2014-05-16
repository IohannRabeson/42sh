/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 22:12:13 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/16 15:38:06 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"

t_bool	str_buf_find_first_char(t_str_buf const *strbuf, char c, t_ui *pos)
{
	t_ui	i;

	i = 0;
	while (i < strbuf->size)
	{
		if (strbuf->buffer[i] == c)
		{
			if (pos)
				*pos = i;
			return (true);
		}
		++i;
	}
	return (false);
}

t_bool	str_buf_find_nth_char(t_str_buf const *strbuf,
								char c,
								t_ui *pos, t_ui n)
{
	t_ui	i;
	t_ui	count;

	i = 0;
	count = 0;
	while (i < strbuf->size)
	{
		if (strbuf->buffer[i] == c)
		{
			++count;
			if (count == n)
			{
				if (pos)
					*pos = i;
				return (true);
			}
		}
		++i;
	}
	return (false);
}
