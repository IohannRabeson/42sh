/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:32:08 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 01:14:09 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "app.h"
#include "path.h"
#include "env.h"
#include <ft_list.h>
#include <ft_str_array.h>
#include <ft_string.h>

static char			*cmd_resolve_exec_path(char const *exec_path,
										   t_app const *app)
{
	char	**paths;
	char	**path_it;
	char	*complete_path;

	paths = ft_strsplit(env_get_value(&app->env, "PATH"), ':');
	if (paths == NULL)
		return (NULL);
	path_it = paths;
	while (path_it && *path_it)
	{
		complete_path = path_concat(*path_it, exec_path);
		if (path_exists(complete_path) && path_is_executable(complete_path))
			return (complete_path);
		else
			free(complete_path);
		++path_it;
	}
	return (NULL);
}

static t_cmd_type	cmd_deduce_type(char **params, t_app const *app)
{
	const t_ui	params_count = str_array_size(params);
	char		*resolved_exec_path;

	if (params_count == 0)
		return (CMD_UNKNOW);
	// Tester ici si c'est un builtin!
	if (path_is_executable(params[0]))
		return (CMD_EXE);
	else	
	{
		resolved_exec_path = cmd_resolve_exec_path(params[0], app);
		free(params[0]);
		params[0] = resolved_exec_path;
		return (CMD_EXE);
	}
	return (CMD_UNKNOW);
}

void	cmd_setup(t_cmd *cmd,
				  t_list const *params,
				  t_app const *app)
{
	if (cmd->params)
		str_array_free(cmd->params);
	cmd->params = str_array_from_list(params);
	cmd->type = cmd_deduce_type(cmd->params, app);
}
