/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:58:17 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 19:36:14 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXEMS_H
# define LEXEMS_H
# include <ft_list_node.h>

struct s_list;

t_list_node	*lexems_find_next(struct s_list_node *lex_it, t_ui state_id);
void		lexems_preprocess(struct s_list *lexems);

#endif
