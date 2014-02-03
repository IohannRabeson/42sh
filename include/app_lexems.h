/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_lexems.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 06:50:59 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/29 19:53:06 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_LEXEMS_H
# define APP_LEXEMS_H
# include <ft_types_def.h>

struct		s_lexem;

t_bool		lexem_is_params(struct s_lexem *lex);
t_bool		lexem_is_operators(struct s_lexem *lex);
t_bool		lexem_is_pipe(struct s_lexem *lex);

#endif
