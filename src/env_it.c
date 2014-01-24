/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_it.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 21:47:12 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 18:53:14 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env_var		*env_begin(t_env *env)
{
	return (env->env_vars);
}

t_env_var		*env_end(t_env *env)
{
	return (env->env_vars + env->count);
}

t_env_var const	*env_cbegin(t_env const *env)
{
	return (env->env_vars);
}

t_env_var const	*env_cend(t_env const *env)
{
	return (env->env_vars + env->count);
}
