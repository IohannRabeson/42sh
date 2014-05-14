/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:59:58 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 04:24:29 by irabeson         ###   ########.fr       */
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
	ft_bzero(histo, sizeof(*histo));
}

void	histo_push(t_histo *histo, char const *str)
{
	char	*nstr;

	nstr = ft_strdup(str);
	list_push_back(&histo->str_list, (void *)nstr);
	histo->current = list_last(&histo->str_list);
}

void	histo_show_prev(t_histo *histo, struct s_textedit *te)
{
	char const	*str;

	if (histo->current == NULL)
		return ;
	str = (char *)histo->current->item;
	if (str)
		textedit_replace_text(te, str);
	if (histo->current->prev)
		histo->current = histo->current->prev;
}

void	histo_show_next(t_histo *histo, struct s_textedit *te)
{
	char const	*str;

	if (histo->current == NULL || histo->current->next == NULL)
		return ;
	histo->current = histo->current->next;
	if (histo->current == NULL)
		return ;
	str = (char *)histo->current->item;
	if (str)
		textedit_replace_text(te, str);
}
