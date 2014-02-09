/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:59:58 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 19:25:24 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "histo.h"
#include "textedit.h"
#include <ft_memory.h>
#include <ft_string.h>
#include <stdlib.h>

void	histo_init(t_histo *histo)
{
	ft_bzero(histo, sizeof(*histo));
	list_init(&histo->str_list, free);
}

void	histo_destroy(t_histo *histo)
{
	list_destroy(&histo->str_list);
	if (histo->old)
		free(histo->old);
	ft_bzero(histo, sizeof(*histo));
}

void	histo_push(t_histo *histo, char const *str)
{
	list_push_back(&histo->str_list, (void *)ft_strdup(str));
	if (histo->old)
		free(histo->old);
	histo->old = NULL;
	histo->current = NULL;
}

void	histo_show_prev(t_histo *histo, struct s_textedit *te)
{
	char const	*str;

	if (histo->current == NULL)
	{
		if (histo->old)
			free(histo->old);
		histo->old = textedit_get_text(te);
		histo->current = histo->str_list.last;
	}
	else if (histo->current->prev)
		histo->current = histo->current->prev;
	if (histo->current == NULL)
		return ;
	str = (char const *)histo->current->item;
	if (str)
		textedit_replace_text(te, str);
}

void	histo_show_next(t_histo *histo, struct s_textedit *te)
{
	char const	*str;

	if (histo->current == NULL)
		return ;
	else if (histo->current->next)
		histo->current = histo->current->next;
	else if (histo->current && histo->old)
	{
		textedit_replace_text(te, histo->old);
		return ;
	}
	if (histo->current == NULL)
		return ;
	str = (char const *)histo->current->item;
	if (str)
		textedit_replace_text(te, str);
}
