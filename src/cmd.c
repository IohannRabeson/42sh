/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:05:11 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 18:50:29 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <ft_str_array.h>
#include <ft_string.h>
#include <ft_memory.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	cmd_init(t_cmd *cmd)
{
	ft_bzero(cmd, sizeof(*cmd));
}

void	cmd_destroy(t_cmd *cmd)
{
	if (cmd->params)
		str_array_free(cmd->params);
	if (cmd->filename)
		free(cmd->filename);
	if (cmd->pid > 0)
		kill(cmd->pid, SIGINT);
	ft_bzero(cmd, sizeof(*cmd));
}
