/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:04:56 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:41:51 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexem.h"
#include <ft_print.h>

void	lexem_put(t_lexem const *lex)
{
	ft_putui(lex->state_id);
	ft_putstr(" - ");
	ft_putstrn(lex->str, lex->size);
	ft_putchar('\n');
}
