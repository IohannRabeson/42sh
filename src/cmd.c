/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:15:39 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 13:27:58 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "app.h"
#include <ft_memory.h>
#include <ft_str_array.h>
#include <ft_error.h>
#include <stdlib.h>

void		cmd_init(t_cmd *cmd)
{
	ft_bzero(cmd, sizeof(*cmd));
}

void		cmd_destroy(t_cmd *cmd)
{
	if (cmd->args)
		str_array_free(cmd->args);
	if (cmd->in_file)
		free(cmd->in_file);
	if (cmd->out_file)
		free(cmd->out_file);
	if (cmd->next)
	{
		cmd_destroy(cmd->next);
		free(cmd->next);
	}
	ft_bzero(cmd, sizeof(*cmd));
}

t_cmd		*cmd_malloc(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(*cmd));
	if (cmd == NULL)
		exit_errorc(STR_APPNAME, ERRC_NOT_ENOUGH_MEMORY, 1);
	cmd_init(cmd);
	return (cmd);
}

void		cmd_free(t_cmd *cmd)
{
	if (cmd)
	{
		cmd_destroy(cmd);
		free(cmd);
	}
}
