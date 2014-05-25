/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 17:28:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 03:02:55 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "histo.h"
#include "textedit.h"
#include <ft_str_buf.h>
#include <ft_string.h>
#include <stdlib.h>

void	histo_show_prev(t_histo *histo, struct s_textedit *te)
{
	char	*str_carry;
	char	*new_text;

	str_carry = textedit_get_text(te);
	new_text = NULL;
	if (list_empty(&histo->str_list) || str_carry == NULL)
		return ;
	if (histo->current && histo->current->next)
		histo->current = histo->current->next;
	else if (histo->current == NULL)
	{
		str_buf_assign(&histo->temp_cmdline, str_carry);
		if (list_empty(&histo->str_list) == false)
			histo->current = list_first(&histo->str_list);
	}
	if (histo->current)
		textedit_replace_text(te, (char const *)histo->current->item);	
	free(str_carry);
	if (new_text)	
		free(new_text);
}

void	histo_show_next(t_histo *histo, struct s_textedit *te)
{
	char const	*str;

	if (histo->current == NULL)
		return ;
	if (histo->current)
		histo->current = histo->current->prev;
	if (histo->current)
		str = ft_strdup((char const *)histo->current->item);
	else
		str = str_buf_get(&histo->temp_cmdline);
	if (str)
		textedit_replace_text(te, str);
}

void	histo_push(t_histo *histo, char const *str)
{
	char	*nstr;

	nstr = ft_strdup(str);
	if (nstr)
		list_push_front(&histo->str_list, (void *)nstr);
	histo->current = NULL;
}
