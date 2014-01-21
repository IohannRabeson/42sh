/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 21:11:54 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 21:58:34 by irabeson         ###   ########.fr       */
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
		if (ft_strcmp(it->key, key) == 1)
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
	while (it != env_cend(env))
	{
		if (ft_strcmp(it->key, key) == 1)
			return (it->value);
		++it;
	}
	return (false);
}

t_env_var		*env_find(t_env *env, char const *key)
{
	t_ui	i;

	i = 0;
	while (i < env->count)
	{
		if (ft_strequ(env->env_vars[i].key, key))
			break ;
		++i;
	}
	return (env->env_vars + i);
}

t_env_var const	*env_cfind(t_env const *env, char const *key)
{
	t_ui	i;

	i = 0;
	while (i < env->count)
	{
		if (ft_strequ(env->env_vars[i].key, key))
			break ;
		++i;
	}
	return (env->env_vars + i);
}
