/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:32:27 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 08:31:36 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

struct s_env;
struct s_cmd;

typedef void(*t_builtin_func)(struct s_cmd *cmd, struct s_env *);

typedef struct	s_builtin
{
	char const		*key;
	t_builtin_func	func;
	char const		*help;
}				t_builtin;

void			builtin_init(t_builtin *btin,
								char const *key,
								char const *help,
								t_builtin_func func);
void			builtin_destroy(t_builtin *btin);
char const		*builtin_key(t_builtin const *btin);

#endif
