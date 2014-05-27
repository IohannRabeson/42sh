/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_chain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 19:32:54 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/27 03:02:52 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "cmd.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ft_types_def.h>
#include <ft_error.h>
#include <ft_print.h>

static int			open_out_fd(char const *filename, t_bool trunc)
{
	int	fd;

	if (filename == NULL)
		return (-1);
	if (trunc)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(filename, O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		exit_errorm(STR_APPNAME,
					"unable to open file for writing", 1, app_destroy);
	}
	return (fd);
}

static void			cmd_exec_chain_child(t_cmd *cmd, int fds[2], int fds_io[2],
											char **env)
{
	char	*complete_bin;

	complete_bin = app_complete_bin_path(cmd->args[0]);
	close(fds[0]);
	dup2(fds_io[0], STDIN_FILENO);
	if (cmd->next == NULL && fds_io[0] != -1)
		dup2(fds_io[1], STDOUT_FILENO);
	else if (cmd->next != NULL)
		dup2(fds[1], STDOUT_FILENO);
	execve(complete_bin, cmd->args, env);
	free(complete_bin);
	exit_errorm(STR_APPNAME, "command execution failed", 1, app_destroy);
}

static void			cmd_exec_chain_parent(t_cmd *cmd, int fds[2], int fds_io[2],
											pid_t pid)
{
	t_app	*app;
	int		status;

	app = app_instance();
	close(fds[1]);
	if (fds_io[1] != -1)
		close(fds_io[1]);
	app->current_cmd = pid;
	waitpid(pid, &status, 0);
	app->current_cmd = 0;
	if (WIFSIGNALED(status))
	{
		cmd_errorl(cmd, 1, "command interupted");
		fds_io[0] = -1;
	}
	else if (status != 0)
	{
		fds_io[0] = -1;
	}
	else if (cmd->next)
		fds_io[0] = fds[0];
	app_set_last_cmd_status(status);
	cmd->exit_code = status;
}

int					cmd_exec_chain(t_cmd *it, char **env, int fd_in)
{
	int		fds[2];
	int		fds_io[2];
	pid_t	pid;

	fds_io[1] = open_out_fd(it->out_file, it->trunc_out);
	fds_io[0] = fd_in;
	if (pipe(fds) == -1)
		exit_errorm(STR_APPNAME, "failed to pipe", 1, app_destroy);
	pid = fork();
	if (pid == 0)
		cmd_exec_chain_child(it, fds, fds_io, env);
	else if (pid > 0)
		cmd_exec_chain_parent(it, fds, fds_io, pid);
	else
		exit_errorm(STR_APPNAME, "failed to fork", 1, app_destroy);
	if (fds_io[1] != -1)
		close(fds_io[1]);
	return (fds_io[0]);
}
