/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit_multiline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 14:41:24 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:03:51 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"
#include <ft_list.h>
#include <ft_error.h>
#include <ft_string.h>
#include <stdlib.h>

static char const	*g_close_br = "\"\'`)]}";
static char const	*g_open_br = "\"\'`([{";

static char		get_close_char(char open)
{
	char	*oc;
	t_ui	offset;

	oc = ft_strchr(g_open_br, open);
	if (oc == NULL)
		return ('\0');
	offset = oc - g_open_br;
	if (offset >= ft_strlen(g_close_br))
		return ('\0');
	return (g_close_br[offset]);
}

static t_bool	brace_stack_pop(t_str_buf *brace_stack, char c)
{
	char last_char;

	if (str_buf_size(brace_stack) == 0)
		return (false);
	last_char = str_buf_get_last_char(brace_stack);
	if (get_close_char(last_char) == c)
		return (true);
	else
		return (false);
}

t_bool			textedit_multiline(t_textedit const *textedit)
{
	t_str_buf			brace_stack;
	t_ui				i;
	char				c;
	t_bool				res;

	str_buf_init(&brace_stack);
	i = 0;
	while (i < str_buf_size(&textedit->buffer))
	{
		c = str_buf_get_char(&textedit->buffer, i);
		if (ft_strchr(g_close_br, c) != NULL
			&& (brace_stack_pop(&brace_stack, c)))
		{
			str_buf_pop_back(&brace_stack);
		}
		else if (ft_strchr(g_open_br, c) != NULL)
		{
			str_buf_app_char(&brace_stack, c);
		}
		++i;
	}
	res = str_buf_size(&brace_stack) > 0;
	str_buf_destroy(&brace_stack);
	return (res);
}
