/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_lexems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 06:50:24 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 06:59:10 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexem.h"
#include "app.h"

t_bool		lexem_is_params(t_lexem *lex)
{
	return (lex && (lexem_type_is(lex, ST_PARAM)
					|| lexem_type_is(lex, ST_FPARAM)));
}

t_bool		lexem_is_operators(t_lexem *lex)
{
	return (lex
			&& (lex->state_id == ST_OP_REDIR_OUT
				|| lex->state_id == ST_OP_REDIR_OUTA
				|| lex->state_id == ST_OP_REDIR_IN
				|| lex->state_id == ST_OP_REDIR_INA
				|| lex->state_id == ST_END_CMD));
}
