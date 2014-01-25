/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:32:27 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 16:51:40 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

struct			s_env;

typedef 		void(*t_buitin_func)(char **, struct s_env *);

typedef struct	s_builtin
{
	char const		*key;
	t_buitin_func	func;
}				t_builtin;

void			builtin_init(t_builtin *btin);
void			builtin_fdestroy(t_builtin *btin);
char const		*builtin_key(t_builtin const *btin);

#endif
