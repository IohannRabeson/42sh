/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 21:33:43 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 21:52:35 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void			env_set(t_env *env, char const *key, char const *value)
{
	t_env_var	*env_var;

	env_var = env_find(env, key);
	if (env_var)
		env_var_set_value(env_var, value);
	else
		env_add_kv(env, key, value);
}

void			env_remove(t_env *env, char const *key)
{
	t_env_var	*env_var;

	env_var = env_find(env, key);
	if (env_var)
	{
		env_var_destroy(env_var);
		++env_var;
		while (env_var != env_end(env))
		{
			*(env_var - 1) = *env_var;
			++env_var;
		}
		env->count -= 1;
	}
}

void			env_clear(t_env *env)
{
	env->count = 0;
}
