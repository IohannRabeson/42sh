/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 21:13:15 by irabeson          #+#    #+#             */
/*   Updated: 2014/06/18 07:36:49 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "app.h"
#include <ft_string.h>

void				bt_cd(t_cmd *cmd, t_env *env)
{
	char const	*pwd;
	t_bool		result;

	result = false;
	pwd = env_get_value(env, "PWD");
	// TODO: check PATH
	if (pwd == NULL)
	{
		cmd_errorl(cmd, 2, "no valid environ");
		return ;
	}
	if (cmd->argc == 1 || cmd->args[1] == NULL)
		result = app_cd(env_get_value(env, "HOME"));
	else if (ft_strequ(cmd->args[1], "-"))
		result = app_cd(env_get_value(env, "OLDPWD"));
	else
		result = app_cd(cmd->args[1]);
	if (result == false)
		cmd_errorl(cmd, 2, "no such a directory");
}
