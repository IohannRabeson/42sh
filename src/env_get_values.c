/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 05:06:50 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 05:40:31 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "ft_list.h"
#include "ft_string.h"

t_ui			env_get_values(t_env const *env, char const *key, char sep,
								struct s_list *results)
{
	t_ui		count;
	char const	*value;

	count = 0;
	value = env_get_value(env, key);
	if (value)
		count = ft_strsplit_list(value, sep, results);
	return (count);
}
