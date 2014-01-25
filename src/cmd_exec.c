/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:56:01 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 01:12:58 by irabeson         ###   ########.fr       */
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

# define	PIPE_IN		0
# define	PIPE_OUT	1

t_bool	cmd_exec(t_cmd *cmd, t_env const *env)
{
	pid_t		pid;
	int			status;
	char		**env_array;
	//int			fds[2];

	//pipe(fds);
	env_array = env_copy_array(env);
	pid = fork();
	cmd->success = false;
	if (pid == 0)
	{
		/*close(fds[PIPE_OUT]);
		if (cmd->fd_in != -1)
			dup2(fds[PIPE_IN], cmd->fd_in);*/
		execve(cmd->params[0], cmd->params, env_array);
		ft_putendl_fd("ft_sh: can't execute command", STDERR_FILENO);
		exit(0);
	}
	else
	{
		/*close(fds[PIPE_IN]);
		if (cmd->fd_out != -1)
			dup2(fds[PIPE_OUT], cmd->fd_out);*/
		waitpid(pid, &status, 0);
		cmd->success = (status == 0);
	}
	str_array_free(env_array);
	return (cmd->success);
	(void)env_array;
}
