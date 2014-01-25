/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 01:34:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 01:35:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexem.h"

t_bool	lexem_type_is(t_lexem *lex, t_ui type)
{
	return (lex->state_id == type);
}