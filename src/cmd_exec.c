/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:58:03 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:14:35 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "app.h"
#include <ft_error.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int	open_in_fd(char const *filename)
{
	int	fd;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_errorm(STR_APPNAME,
					"Unable to open file to reading", 1, app_destroy);
	return (fd);
}

void		cmd_exec(t_cmd *cmd, char **env)
{
	int		fd_in;
	int		old_fd_in;
	t_cmd	*it;

	it = cmd;
	if (cmd->in_file)
		fd_in = open_in_fd(it->in_file);
	else
		fd_in = STDIN_FILENO;
	old_fd_in = -1;
	while (it)
	{
		old_fd_in = fd_in;
		fd_in = cmd_exec_chain(it, env, fd_in);
		if (fd_in == -1)
			break ;
		if (old_fd_in != STDIN_FILENO)
			close(old_fd_in);
		it = it->next;
	}
}
