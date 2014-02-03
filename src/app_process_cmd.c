/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_process_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:13:23 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/03 20:04:16 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "cmd.h"
#include "env.h"
#include <ft_print.h>

t_bool	app_process_cmd(t_cmd *cmd, t_env const *env)
{
	t_bool			result;

	result = true;
/*	if (cmd_is_builtin(cmd))
	{
		ft_putstr("Execute builtin: ");
		ft_putendl(cmd->params[0]);
	//	cmd_exec_builtin(cmd, env);
	}
	else if (cmd_is_exec(cmd))
	{
		ft_putstr("Execute command: ");
		ft_putendl(cmd->params[0]);
//		cmd_exec(cmd, env);
	}
	else
		result = false;
	cmd_destroy(cmd);
	*/
	return (result);
	(void)env;
	(void)cmd;
}
