/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:59:58 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 00:27:31 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "histo.h"
#include "textedit.h"
#include <ft_memory.h>
#include <ft_string.h>
#include <ft_list.h>
#include <stdlib.h>

void	histo_init(t_histo *histo)
{
	ft_bzero(histo, sizeof(*histo));
	list_init(&histo->str_list, free);
	str_buf_init(&histo->temp_cmdline);
}

void	histo_destroy(t_histo *histo)
{
	list_destroy(&histo->str_list);
	str_buf_destroy(&histo->temp_cmdline);
	ft_bzero(histo, sizeof(*histo));
}

void	histo_push(t_histo *histo, char const *str)
{
	char	*nstr;

	nstr = ft_strdup(str);
	list_push_front(&histo->str_list, (void *)nstr);
	histo->current = NULL;
}

t_ui	histo_size(t_histo const *histo)
{
	return list_count(&histo->str_list);
}

void	histo_show_next(t_histo *histo, struct s_textedit *te)
{
	char const	*str;
	char		*temp_str;

	if (histo->current == NULL)
	{
		temp_str = str_buf_get(&histo->temp_cmdline);
		if (temp_str)
		{
			textedit_replace_text(te, temp_str);
			free(temp_str);
			temp_str = NULL;
		}
		return ;
	}
	else
		histo->current = histo->current->prev;
	if (histo->current)
	{
		str = (char *)histo->current->item;
		if (str)
			textedit_replace_text(te, str);
	}
}
