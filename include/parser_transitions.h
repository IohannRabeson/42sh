/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_transitions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:15:08 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 15:24:18 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TRANSITIONS_H
# define PARSER_TRANSITIONS_H
# include "ft_types_def.h"

# define	PARSER_MAX_STATE	127
# define	PARSER_ERR_STATE	PARSER_MAX_STATE

typedef struct	s_transitions
{
	t_ui			nexts[PARSER_MAX_STATE];
}				t_transitions;

void			transitions_init(t_transitions *trans);
void			transitions_destroy(t_transitions *trans);
void			transitions_clear(t_transitions *trans);
t_ui			transitions_get_next(t_transitions const *trans, char c);
void			transitions_set_next(t_transitions *trans, t_ui next, char c);

#endif
