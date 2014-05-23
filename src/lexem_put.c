/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:04:56 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/23 22:49:43 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexem.h"
#include "app.h"
#include <ft_print.h>

static char const	*g_lexem_types[ST_OP_COUNT] =
{
	"[INIT]",
	"[SPACES]",
	"[PARAMETER]",
	"[ENCLOSED PARAMETER]",
	"[BRACE OPEN]",
	"[BRACE CLOSE]",
	"[EOC]",
	"[REDIR OUT OP]",
	"[REDIR OUT APP OP",
	"[REDIR IN OP]",
	"[PIPE OP]",
	"[ASSIGN OP]"
};

static void			display_type(unsigned int type)
{
	if (type < ST_OP_COUNT)
	{
		ft_putstr(g_lexem_types[type]);
		ft_putchar(' ');
	}
	else
	{
		ft_putendl("Mauvais type de lexem, pauv' tache...");
		ft_putendl("Ha ouai tiens ton identifiant pourri là: ");
		ft_putui(type);
		ft_putchar('\n');
	}
}

void				lexem_put(t_lexem const *lex)
{
	display_type(lex->state_id);
	ft_putstr(" ");
	ft_putstrn(lex->str, lex->size);
	ft_putchar('\n');
}
