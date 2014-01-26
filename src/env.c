/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:26:02 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/26 02:45:04 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>
#include <ft_memory.h>
#include <ft_string.h>
#include <ft_error.h>
#include <ft_str_array.h>
#include <unistd.h>

void		env_init(t_env *env, char **environs)
{
	const t_ui	count = str_array_size(environs);
	t_ui		i;
	char		buffer[1024];

	ft_bzero((void *)env, sizeof(env));
	env_reserve(env, count);
	i = 0;
	while (i < count && environs[i])
	{
		env_add(env, environs[i]);
		++i;
	}
	if (i == 0)
	{
		getcwd(buffer, 1024);
		env_set(env, "PWD", buffer);
	}
}

void		env_destroy(t_env *env)
{
	t_ui	i;

	i = 0;
	if (env->env_vars)
	{
		while (i < env->count)
			env_var_destroy(&env->env_vars[i++]);
		free(env->env_vars);
		env->env_vars = NULL;
	}
}

void	env_reserve(t_env *env, t_ui new_cap)
{
	t_ui		i;
	t_ui		new_count;
	t_env_var	*new;

	if (new_cap == env->capacity)
		return ;
	new = (t_env_var *)malloc(sizeof(*new) * new_cap);
	if (new == NULL)
		exit_errorc(ERRC_NOT_ENOUGH_MEMORY);
	i = 0;
	new_count = (new_cap < env->count) ? new_cap : env->count;
	while (i < new_count)
	{
		new[i] = env->env_vars[i];
		++i;
	}
	if (env->env_vars)
		free(env->env_vars);
	env->env_vars = new;
	env->capacity = new_cap;
	env->count = new_count;
}

void	env_add(t_env *env, char const *str)
{
	if (str == NULL)
		return ;
	if (env->count == env->capacity)
		env_reserve(env, env->capacity + 1);
	env_var_init(&env->env_vars[env->count++], str);
}

void	env_add_kv(t_env *env, char const *key, char const *value)
{
	if (key == NULL)
		return ;
	if (env->count == env->capacity)
		env_reserve(env, env->capacity + 1);
	env_var_init_kv(&env->env_vars[env->count++], key, value);
}
