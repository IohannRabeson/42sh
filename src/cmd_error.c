/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:10:15 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/03 20:14:00 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <ft_print.h>
#include <unistd.h>

void		cmd_errorl(t_cmd const *cmd, t_ui level, char const *msg)
{
	t_ui	i;

	i = 0;
	ft_putstr_fd(cmd->args[0], STDERR_FILENO);
	while (i < level && i < cmd->argc && cmd->args[i])
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(cmd->args[i], STDERR_FILENO);
		++i;
	}
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}
