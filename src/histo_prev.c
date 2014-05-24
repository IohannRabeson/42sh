/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo_prev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 17:28:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 00:26:23 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "histo.h"
#include "textedit.h"
#include <ft_str_buf.h>
#include <stdlib.h>

void	histo_show_prev(t_histo *histo, struct s_textedit *te)
{
	char const	*str;
	char		*current_cmdline;

	if (list_empty(&histo->str_list))
		return ;
	if (histo->current == NULL)
	{
		current_cmdline = textedit_get_text(te);
		if (current_cmdline)
		{
			str_buf_clear(&histo->temp_cmdline);
			str_buf_app_str(&histo->temp_cmdline, current_cmdline);
			free(current_cmdline);
			current_cmdline = NULL;
		}
		histo->current = list_first(&histo->str_list);
	}
	if (histo->current)
	{
		str = (char *)histo->current->item;
		if (str)
			textedit_replace_text(te, str);
	}
}
