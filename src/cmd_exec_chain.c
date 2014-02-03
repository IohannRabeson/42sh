/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_chain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 19:32:54 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/03 19:52:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ft_types_def.h>
#include <ft_error.h>
#include <ft_print.h>
#include "cmd.h"

static int			open_out_fd(char const *filename, t_bool trunc)
{
	int	fd;

	if (filename == NULL)
		return (-1);
	if (trunc)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		exit_errorm("Unable to open file for writing");
	return (fd);
}

static void			cmd_exec_chain_child(t_cmd *cmd,
										 int fds[2],
										 int fds_io[2],
										 char **env)
{
	close(fds[0]);
	dup2(fds_io[0], STDIN_FILENO);
	if (cmd->next == NULL && fds_io[0] != -1)
		dup2(fds_io[1], STDOUT_FILENO);
	else if (cmd->next != NULL)
		dup2(fds[1], STDOUT_FILENO);
	execve(cmd->args[0], cmd->args, env);
	exit_errorm("Failed to exec command");
}

static void			cmd_exec_chain_parent(t_cmd *cmd,
										  int fds[2],
										  int fds_io[2],
										  pid_t pid)
{
	int	status;

	close(fds[1]);
	if (fds_io[1] != -1)
		close(fds_io[1]);
	waitpid(pid, &status, 0);
	if (status != 0)
	{
		ft_putstr_fd("ft_sh: ", STDERR_FILENO);
		ft_putstr_fd(cmd->args[0], STDERR_FILENO);
		ft_putendl_fd(": execution failed", STDERR_FILENO);
		fds_io[0] = -1;
	}
	else if (cmd->next)
		fds_io[0] = fds[0];
}

int					cmd_exec_chain(t_cmd *it, char **env, int fd_in)
{
	int		fds[2];
	int		fds_io[2];
	pid_t	pid;

	fds_io[1] = open_out_fd(it->out_file, true);
	fds_io[0] = fd_in;
	pipe(fds);
	pid = fork();
	if (pid == 0)
		cmd_exec_chain_child(it, fds, fds_io, env);
	else if (pid > 0)
		cmd_exec_chain_parent(it, fds, fds_io, pid);
	else
		exit_errorm("failed to fork");
	close(fds_io[1]);
	return (fds_io[0]);
}
