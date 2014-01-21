/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 22:45:10 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 22:47:14 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
