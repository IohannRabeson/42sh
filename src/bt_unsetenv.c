/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 01:34:59 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 01:44:19 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include <ft_string.h>

void		bt_unsetenv(t_cmd *cmd, t_env *env)
{
	char	*key;

	if (cmd->argc < 1)
		return ;
	key = cmd->args[1];
	if (key && ft_strlen(key) > 0)
	{
		if (env_cfind(env, key))
			env_remove(env, key);
	}
	(void)env;
}
