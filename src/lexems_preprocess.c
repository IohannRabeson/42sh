/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems_preprocess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:56:11 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 01:26:43 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "lexem.h"
#include <ft_list.h>
#include <ft_string.h>
#include <stdlib.h>

static t_bool		lexem_is_spaces(t_lexem *lex)
{
	return (lexem_type_is(lex, ST_SKIP_SPACES));
}

static void			lexem_in_place(t_lexem *lexem)
{
	char	*str;

	if (lexem->str)
	{
		str = ft_strndup(lexem->str, lexem->size);
		free(lexem->str);
		lexem->str = str;
	}
}

void				lexems_remove_spaces(t_list *lexems)
{
	list_erase_if(lexems, lexem_is_spaces);
}

void				lexems_preprocess(t_list *lexems)
{
	list_foreach(lexems, lexem_in_place);
	lexems_remove_spaces(lexems);
}
