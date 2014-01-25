/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:07:43 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 19:20:16 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "path.h"
#include <fcntl.h>
#include <unistd.h>

t_bool	cmd_exec_open_ofile(t_cmd *cmd, int *fd_out)
{
	int	fd;
	int	flag;

	fd = -1;
	*fd_out = -1;
	flag = O_WRONLY | O_CREAT;
	if (cmd->mode == CMD_MODE_REDIR_OUT)
		flag |= O_TRUNC;
	if (cmd->filename)
	{
		fd = open(cmd->filename, flag, 0644);
		if (fd == -1)
			cmd_error(cmd, "file not openable");
		*fd_out = fd;
	}
	return (fd != -1);
}

t_bool	cmd_exec_open_ifile(t_cmd *cmd, int *fd_in)
{
	int	fd;

	*fd_in = -1;
	fd = -1;
	if (cmd->filename)
	{
		fd = open(cmd->filename, O_RDONLY);
		if (fd == -1)
			cmd_error(cmd, "file not openable");
		*fd_in = fd;
	}
	return (fd != -1);
}
