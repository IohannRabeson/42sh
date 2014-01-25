/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:32:27 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:37:53 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

struct			s_env;
struct			s_cmd;

typedef 		void(*t_builtin_func)(struct s_cmd *cmd, struct s_env const *);

typedef struct	s_builtin
{
	char const		*key;
	t_builtin_func	func;
}				t_builtin;

void			builtin_init(t_builtin *btin,
							 char const *key,
							 t_builtin_func func);
void			builtin_destroy(t_builtin *btin);
char const		*builtin_key(t_builtin const *btin);

#endif
