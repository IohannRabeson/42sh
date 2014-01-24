/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 22:45:10 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:11:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <ft_str_buf.h>
#include <ft_str_array.h>
#include <stdlib.h>

void	env_copy(t_env *dest, t_env const *env)
{
	t_env_var const	*it;

	it = env_cbegin(env);
	while (it != env_cend(env))
	{
		env_add_kv(dest, it->key, it->value);
		++it;
	}
}

char	**env_copy_array(t_env const *env)
{
	char			**new_array;
	t_env_var const	*it;
	t_env_var const	*end;
	t_str_buf		strbuf;
	t_ui			i;

	str_buf_init(&strbuf);
	new_array = str_array_malloc(env_count(env));
	if (new_array == NULL)
		return (NULL);
	i = 0;
	it = env_cbegin(env);
	end = env_cend(env);
	while (it < end)
	{
		str_buf_app_str(&strbuf, it->key);
		str_buf_app_char(&strbuf, '=');
		str_buf_app_str(&strbuf, it->value);
		new_array[i] = str_buf_get(&strbuf);
		str_buf_clear(&strbuf);
		++it;
		++i;
	}
	new_array[i] = NULL;
	str_buf_destroy(&strbuf);
	return (new_array);
}
