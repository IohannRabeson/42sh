/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:23:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:35:44 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include <ft_string.h>

void		bt_setenv(t_cmd *cmd, t_env *env)
{
	char	*key;
	char	*value;

	if (cmd->argc < 2)
		return ;
	key = cmd->args[1];
	value = cmd->args[2];
	if (key && value && ft_strlen(key) > 0 && ft_strlen(value) > 0)
	{
		if (env_cfind(env, key) == NULL)
			env_add_kv(env, key, value);
		else
			env_set(env, key, value);
	}
}
