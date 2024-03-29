/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 21:11:54 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/26 02:52:24 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <libft.h>

t_bool			env_contains(t_env const *env, char const *key)
{
	t_env_var const	*it;

	it = env_cbegin(env);
	while (it != env_cend(env))
	{
		if (ft_strcmp(it->key, key) == 0)
			return (true);
		++it;
	}
	return (false);
}

t_ui			env_count(t_env const *env)
{
	return (env->count);
}

char const		*env_get_value(t_env const *env, char const *key)
{
	t_env_var const	*it;

	it = env_cbegin(env);
	while (it && it != env_cend(env))
	{
		if (ft_strequ(it->key, key))
			return (it->value);
		++it;
	}
	return (NULL);
}

t_env_var		*env_find(t_env *env, char const *key)
{
	t_ui	i;

	i = 0;
	while (i < env->count)
	{
		if (ft_strequ(env->env_vars[i].key, key))
			return (env->env_vars + i);
		++i;
	}
	return (NULL);
}

t_env_var const	*env_cfind(t_env const *env, char const *key)
{
	t_ui	i;

	i = 0;
	while (i < env->count)
	{
		if (ft_strequ(env->env_vars[i].key, key))
			return (env->env_vars + i);
		++i;
	}
	return (NULL);
}
