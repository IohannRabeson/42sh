/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:56:01 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 06:30:16 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include <ft_str_array.h>
#include <ft_print.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

static const	t_cmd_exec_func	g_cmd_exec_funcs[CMD_COUNT] = 
{
	NULL,
	cmd_exec_simple,
	cmd_exec_redir_out,
	cmd_exec_redir_in,
};

t_bool	cmd_exec(t_cmd *cmd, t_env const *env)
{
	t_cmd_exec_func	func;

	func = g_cmd_exec_funcs[cmd->type];
	if (func)
		return (func(cmd, env));
	else
		return (false);
}

t_bool	cmd_exec_simple(t_cmd *cmd, t_env const *env)
{
	pid_t		pid;
	int			status;
	char		**env_array;

	env_array = env_copy_array(env);
	pid = fork();
	cmd->success = false;
	if (pid == -1)
	{
		ft_putstr_fd("ft_sh: ", STDERR_FILENO);
		ft_putstr_fd(cmd->params[0], STDERR_FILENO);
		ft_putendl_fd(": oops", STDERR_FILENO);
	}
	else if (pid == 0)
	{
		execve(cmd->params[0], cmd->params, env_array);
		ft_putendl_fd("ft_sh: can't execute command", STDERR_FILENO);
		exit(0);
	}
	else
	{
		cmd->pid = pid;
		waitpid(pid, &status, 0);
		cmd->success = (status == 0);
		cmd->pid = -1;
	}
	str_array_free(env_array);
	return (cmd->success);
	(void)env_array;
}

t_bool	cmd_exec_redir_out(t_cmd *cmd, t_env const *env)
{
	pid_t		pid;
	int			status;
	char		**env_array;

	env_array = env_copy_array(env);
	pid = fork();
	cmd->success = false;
	if (pid == -1)
	{
		ft_putstr_fd("ft_sh: ", STDERR_FILENO);
		ft_putstr_fd(cmd->params[0], STDERR_FILENO);
		ft_putendl_fd(": oops", STDERR_FILENO);
	}
	else if (pid == 0)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		execve(cmd->params[0], cmd->params, env_array);
		ft_putendl_fd("ft_sh: can't execute command", STDERR_FILENO);
		exit(0);
	}
	else
	{
		close(cmd->fd_out);
		waitpid(pid, &status, 0);
		cmd->success = (status == 0);
	}
	str_array_free(env_array);
	return (cmd->success);
}

t_bool	cmd_exec_redir_in(t_cmd *cmd, t_env const *env)
{
	pid_t		pid;
	int			status;
	char		**env_array;

	env_array = env_copy_array(env);
	pid = fork();
	cmd->success = false;
	if (pid == -1)
	{
		ft_putstr_fd("ft_sh: ", STDERR_FILENO);
		ft_putstr_fd(cmd->params[0], STDERR_FILENO);
		ft_putendl_fd(": oops", STDERR_FILENO);
	}
	else if (pid == 0)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		execve(cmd->params[0], cmd->params, env_array);
		ft_putendl_fd("ft_sh: can't execute command", STDERR_FILENO);
		exit(0);
	}
	else
	{
		close(cmd->fd_in);
		waitpid(pid, &status, 0);
		cmd->success = (status == 0);
	}
	str_array_free(env_array);
	return (cmd->success);
}
