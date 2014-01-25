/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:05:11 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 01:24:41 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <ft_str_array.h>
#include <stdlib.h>
#include <unistd.h>

void	cmd_init(t_cmd *cmd)
{
	cmd->params = NULL;
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	cmd->success = false;
}

void	cmd_destroy(t_cmd *cmd)
{
	if (cmd->params)
	{
		str_array_free(cmd->params);
		cmd->params = NULL;
	}
	if (cmd->fd_in != -1 && cmd->fd_in != STDIN_FILENO)
	{
		close(cmd->fd_in);
		cmd->fd_in = -1;
	}
	if (cmd->fd_out != -1 && cmd->fd_out != STDOUT_FILENO)
	{
		close(cmd->fd_out);
		cmd->fd_out = -1;
	}
	cmd->success = false;
}
