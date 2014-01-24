/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:56:01 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:15:03 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include <ft_str_array.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

# define	PIPE_IN		0
# define	PIPE_OUT	1

t_bool	cmd_exec(t_cmd *cmd, t_env const *env)
{
	//pid_t		pid;
	//int			status;
	char		**env_array;

	env_array = env_copy_array(env);
/*	pid = fork();
	if (pid == 0)
	{
		execve(cmd->params[0], cmd->params, env_array); 
	}
	else
	{
		waitpid(pid, &status, 0);
		cmd->success = (status == 0);
	}*/
	str_array_free(env_array);
	return (cmd->success);
	(void)env_array;
}
