/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:46:07 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 22:11:14 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"
#include <libft.h>
#include <stdlib.h>

static void	ft_str_toupper(char *str)
{
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		++str;
	}
}

t_bool		env_var_init_kv(t_env_var *env_var, char const *key,
							char const *value)
{
	if (key == NULL)
		return (false);
	env_var->key = ft_strdup(key);
	if (value)
		env_var->value = ft_strdup(value);
	else
		env_var->value = NULL;
	if (env_var->key)
		ft_str_toupper(env_var->key);
	return (env_var->key && (value == NULL || env_var->value));
}

t_bool		env_var_init(t_env_var *env_var, char const *str)
{
	char const	*equal_pos;

	if (str == NULL)
		return (false);
	equal_pos = ft_strchr(str, '=');
	if (equal_pos)
	{
		env_var->key = ft_strndup(str, (size_t)(equal_pos - str));
		env_var->value = ft_strdup(equal_pos + 1);
	}
	else
	{
		env_var->key = ft_strtrim(str);
		env_var->value = NULL;
	}
	if (env_var->key)
		ft_str_toupper(env_var->key);
	return (env_var->key && (equal_pos == NULL || env_var->value));
}

void		env_var_destroy(t_env_var *env_var)
{
	if (env_var->key)
	{
		free(env_var->key);
		env_var->key = NULL;
	}
	if (env_var->value)
	{
		free(env_var->value);
		env_var->value = NULL;
	}
}

void		env_var_set_value(t_env_var *env_var, char const *value)
{
	if (env_var->value)
		free(env_var->value);
	env_var->value = ft_strdup(value);
}
