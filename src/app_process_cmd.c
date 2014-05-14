/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_process_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:13:23 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:26:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "cmd.h"
#include "env.h"
#include "builtin.h"
#include "builtins.h"
#include <ft_print.h>
#include <ft_str_array.h>

static t_bool	app_cmd_is_builtin(t_cmd const *cmd)
{
	t_app const *app;

	app = app_instance();
	if (cmd && cmd->argc > 0 && cmd->args && cmd->args[0])
	{
		if (builtins_find(&app->builtins, cmd->args[0]))
			return (true);
	}
	return (false);
}

static t_bool	app_cmd_is_exec(t_cmd const *cmd)
{
	char	*complete_path;
	t_bool	res;

	res = false;
	complete_path = NULL;
	if (cmd && cmd->argc > 0 && cmd->args && cmd->args[0])
	{
		complete_path = app_complete_bin_path(cmd->args[0]);
		if (complete_path == NULL)
			res = false;
		else
			res = true;
	}
	if (complete_path)
		free(complete_path);
	return (res);
}

t_bool			app_process_cmd(t_cmd *cmd, t_env *env)
{
	t_app	*app;
	char	**env_str;

	app = app_instance();
	env_str = env_copy_array(&app->env);
	if (app_cmd_is_builtin(cmd))
		app_process_builtin(cmd, env);
	else if (app_cmd_is_exec(cmd))
		cmd_exec(cmd, env_str);
	else
	{
		cmd_errorl(cmd, 1, "unknow command");
		return (false);
	}
	str_array_free(env_str);
	return (true);
}

t_bool			app_process_builtin(t_cmd *cmd, t_env *env)
{
	t_app		*app;
	t_builtin	*it;

	app = app_instance();
	it = builtins_find(&app->builtins, cmd->args[0]);
	if (it == NULL)
		return (false);
	it->func(cmd, env);
	return (true);
}
