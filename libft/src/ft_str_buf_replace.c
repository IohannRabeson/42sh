/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 23:31:19 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/16 15:39:17 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_buf.h"
#include "ft_string.h"

static void	buf_find(t_bool *match, t_ui *temp_start, t_ui *i, t_ui *j)
{
	*i = 0;
	*j = 0;
	*temp_start = 0;
	*match = false;
}

t_bool		str_buf_find(t_str_buf *str_buf, char const *search, t_ui *start)
{
	t_ui	i;
	t_ui	j;
	t_ui	temp_start;
	t_bool	match;

	buf_find(&match, &temp_start, &i, &j);
	while (i < str_buf_size(str_buf) && search[j] != '\0')
	{
		if (str_buf_get_char(str_buf, i) == search[j])
		{
			if (match == false)
				temp_start = i;
			match = true;
			++j;
		}
		else
		{
			match = false;
			j = 0;
		}
		++i;
	}
	if (match && start)
		*start = temp_start;
	return (match);
}

void		str_buf_replace_all(t_str_buf *str_buf,
								char const *rep_str,
								char const *new_str)
{
	t_ui	start;

	while (str_buf_find(str_buf, rep_str, &start))
	{
		str_buf_erase(str_buf, start, ft_strlen(rep_str));
		str_buf_insert_str(str_buf, start, new_str);
	}
}
