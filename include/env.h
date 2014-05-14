/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:40:15 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 18:43:06 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "env_var.h"
# include <ft_types_def.h>

struct s_list;

typedef struct	s_env
{
	t_env_var	*env_vars;
	t_ui		count;
	t_ui		capacity;
}				t_env;

void			env_init(t_env *env, char **environ);
void			env_destroy(t_env *env);
void			env_reserve(t_env *env, t_ui new_cap);
void			env_add(t_env *env, char const *str);
void			env_add_kv(t_env *env, char const *key, char const *value);
t_bool			env_contains(t_env const *env, char const *key);
t_ui			env_count(t_env const *env);
char const		*env_get_value(t_env const *env, char const *key);
t_ui			env_get_values(t_env const *env, char const *key, char sep,
								struct s_list *results);
void			env_set(t_env *env, char const *key, char const *value);
void			env_remove(t_env *env, char const *key);
void			env_clear(t_env *env);
t_env_var		*env_begin(t_env *env);
t_env_var		*env_end(t_env *env);
t_env_var const	*env_cbegin(t_env const *env);
t_env_var const	*env_cend(t_env const *env);
t_env_var		*env_find(t_env *env, char const *key);
t_env_var const	*env_cfind(t_env const *env, char const *key);
void			env_copy(t_env *dest, t_env const *env);
char			**env_copy_array(t_env const *env);

#endif
