/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems_find_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 23:18:01 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/03 23:20:36 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexem.h"
#include <ft_list_node.h>
#include <stdlib.h>

t_list_node	*lexems_find_next(t_list_node *lex_it, t_ui state_id) 
{
	t_lexem	*lex;

	if (lex_it == NULL)
		return (NULL);
	while (lex_it && lex_it->item)
	{
		lex = (t_lexem *)lex_it->item;
		if (lex->state_id == state_id)
			return (lex_it);
		lex_it = lex_it->next;
	}
	return (NULL);
}
