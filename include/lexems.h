/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:58:17 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/29 17:59:45 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXEMS_H
# define LEXEMS_H

struct	s_list;

void				lexems_remove_spaces(struct s_list *lexems);
void				lexems_preprocess(struct s_list *lexems);

#endif
