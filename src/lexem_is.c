/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 01:34:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:51:08 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexem.h"
#include "app.h"
#include <ft_string.h>

t_bool		lexem_type_is(t_lexem *lex, t_ui type)
{
	return (lex->state_id == type);
}

t_bool		lexem_is_spaces(t_lexem *lex)
{
	return (lexem_type_is(lex, ST_SKIP_SPACES));
}

t_bool		lexem_is_delim(t_lexem *lex)
{
	return (lexem_type_is(lex, ST_DELIM_PARAM_OUT)
	|| lexem_type_is(lex, ST_DELIM_PARAM_IN));
}

t_bool		lexem_is_constant(t_lexem const *lex)
{
	if (lex == NULL && lex->state_id != ST_PARAM)
		return (false);
	return (lex->str && lex->str[0] == '$' && ft_strlen(lex->str) > 1);
}
