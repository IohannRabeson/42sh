/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_process_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:13:23 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/26 17:23:05 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "cmd.h"
#include "env.h"

t_bool	app_process_cmd(t_cmd *cmd, t_env const *env)
{
	t_bool			result;

	result = true;
	if (cmd_is_builtin(cmd))
		cmd_exec_builtin(cmd, env);
	else if (cmd_is_exec(cmd))
		cmd_exec(cmd, env);
	else
		result = false;
	cmd_destroy(cmd);
	return (result);
}
