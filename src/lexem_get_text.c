/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_get_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 01:40:44 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 01:44:40 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexem.h"
#include <ft_string.h>

char	*lexem_get_text(t_lexem const *lex)
{
	return (ft_strndup(lex->str, lex->size));
}
