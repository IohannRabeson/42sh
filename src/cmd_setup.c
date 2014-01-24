/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:32:08 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 17:22:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "app.h"
#include "path.h"
#include "env.h"
#include <ft_list.h>
#include <ft_str_array.h>
#include <ft_string.h>

static t_cmd_type	cmd_deduce_type(char **params, t_app const *app)
{
	const t_ui	params_count = str_array_size(params);
	char		*resolved_exec_path;

	if (params_count == 0)
		return (CMD_UNKNOW);
	// Tester ici si c'est un builtin!
	if (path_is_absolute(params[0]) && path_is_executable(params[0]))
		return (CMD_EXE);
	if (path_is_relative(params[0]))
	{
		resolved_exec_path =
			ft_strjoin(env_get_value(&app->env, "PWD"), params[0]);
		free(params[0]);
		params[0] = resolved_exec_path;
		return (CMD_EXE);
	}
	return (CMD_UNKNOW);
}

void	cmd_setup(t_cmd *cmd,
				  struct s_list const *params,
				  struct s_app const *app)
{
	if (cmd->params)
		str_array_free(cmd->params);
	cmd->params = str_array_from_list(params);
	cmd->type = cmd_deduce_type(cmd->params, app);
}
