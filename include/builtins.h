/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:22:03 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:49:44 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <ft_types_def.h>

struct			s_env;
struct			s_builtin;

typedef struct	s_builtins
{
	struct s_builtin	*builtins;
	t_ui				size;
	t_ui				capacity;
}				t_builtins;

void				builtins_init(t_builtins *bts);
void				builtins_destroy(t_builtins *bts);
void				builtins_reserve(t_builtins *bts, t_ui new_cap);
void				builtins_clear(t_builtins *bts);
void				builtins_add(t_builtins *bts, struct s_builtin const *bt);
struct s_builtin	*builtins_find(t_builtins const *bts, char const *key);
void				builtins_load(t_builtins *bts,
								  struct s_builtin const *builtins);

#endif
