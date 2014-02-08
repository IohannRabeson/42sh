/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 20:03:13 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:17:28 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "lexem.h"
#include "parser_matrix.h"
#include <stdlib.h>
#include <ft_error.h>
#include <ft_memory.h>
#include <ft_string.h>

t_lexem	*lexem_malloc(void)
{
	t_lexem	*new;

	new = (t_lexem *)malloc(sizeof(*new));
	if (new == NULL)
		exit_errorc(STR_APPNAME, ERRC_NOT_ENOUGH_MEMORY, 1, app_destroy);
	new->str = NULL;
	lexem_set(new, PARSER_ERR_STATE, NULL, 0);
	return (new);
}

void	lexem_free(t_lexem *lex)
{
	if (lex)
	{
		if (lex->str)
			free(lex->str);
		free(lex);
	}
}

void	lexem_set(t_lexem *lex, t_ui state_id, char const *str, t_ui size)
{
	lex->state_id = state_id;
	if (lex->str)
		ft_memdel((void **)&lex->str);
	lex->str = ft_strndup(str, size);
	lex->size = size;
}

void	lexem_clear(t_lexem *lex)
{
	lex->state_id = PARSER_ERR_STATE;
	lex->size = 0;
	ft_memdel((void **)&lex->str);
}

t_lexem	*lexem_clone(t_lexem const *lex)
{
	t_lexem	*clone;

	clone = lexem_malloc();
	clone->state_id = lex->state_id;
	clone->str = ft_strdup(lex->str);
	clone->size = lex->size;
	return (clone);
}
