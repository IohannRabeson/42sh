/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:31:30 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:34:42 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "app.h"
#include "builtins.h"
#include "builtin.h"

t_bool	cmd_exec_builtin(t_cmd *cmd, t_env const *env)
{
	t_app const * const	app = app_instance();
	t_builtin			*bt;

	bt = builtins_find(&app->builtins, cmd->params[0]);
	if (bt)
		bt->func(cmd, env);
	return (bt != NULL);
}
