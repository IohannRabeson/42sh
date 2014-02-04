/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:56:17 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 01:22:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXEM_H
# define LEXEM_H
# include <ft_types_def.h>

typedef struct	s_lexem
{
	t_ui	state_id;
	char	*str;
	t_ui	size;
}				t_lexem;

t_lexem		*lexem_malloc(void);
void		lexem_free(t_lexem *lex);
void		lexem_set(t_lexem *lex, t_ui state_id, char const *str, t_ui size);
void		lexem_clear(t_lexem *lex);
t_lexem		*lexem_clone(t_lexem const *lex);
void		lexem_put(t_lexem const *lex);
t_bool		lexem_type_is(t_lexem *lex, t_ui type);
char		*lexem_get_text(t_lexem const *lex);

#endif
