/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:26:02 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 21:39:40 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "env.h"
#include <stdlib.h>
#include <ft_memory.h>
#include <ft_string.h>
#include <ft_error.h>
#include <ft_str_array.h>
#include <unistd.h>

static void	env_setup_imp(t_env *env, t_ui count)
{
	t_env_var	*shlvl;
	t_env_var	*pwd;
	int			lvl;
	char		*lvl_str;
	char		buffer[512];

	lvl = 0;
	shlvl = env_find(env, "SHLVL");
	pwd = env_find(env, "PWD");
	if (pwd == NULL)
	{
		getcwd(buffer, 512);
		env_set(env, "PWD", buffer);
	}
	if (shlvl)
		lvl = ft_atoi(shlvl->value);
	lvl_str = ft_itoa(lvl + 1);
	if (count > 0 && lvl_str)
	{
		env_set(env, "SHLVL", lvl_str);
		free(lvl_str);
	}
}

void		env_init(t_env *env, char **environs)
{
	t_ui const	count = str_array_size(environs);
	t_ui		i;

	ft_bzero((void *)env, sizeof(*env));
	if (environs == NULL)
		return ;
	env_reserve(env, count);
	i = 0;
	while (i < count && environs[i])
	{
		env_add(env, environs[i]);
		++i;
	}
	env_setup_imp(env, i);
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

void		env_reserve(t_env *env, t_ui new_cap)
{
	t_ui		i;
	t_ui		new_count;
	t_env_var	*new;

	if (new_cap == env->capacity)
		return ;
	new = (t_env_var *)malloc(sizeof(*new) * new_cap);
	if (new == NULL)
		exit_errorc(STR_APPNAME, ERRC_NOT_ENOUGH_MEMORY, 1, app_destroy);
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
