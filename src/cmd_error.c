/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:58:48 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 19:15:57 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <ft_print.h>
#include <unistd.h>

void			cmd_error(t_cmd const *cmd, char const *msg)
{
	cmd_errorl(cmd, 1, msg);
}

void			cmd_errorl(t_cmd const *cmd, t_ui level, char const *msg)
{
	t_ui	i;

	i = 0;
	ft_putstr_fd("ft_sh: ", STDERR_FILENO);
	if (cmd && cmd->params)
	{
		while (i < level && cmd->params[i])
		{
			ft_putstr_fd(cmd->params[i], STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			++i;
		}
	}
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	else
		ft_putstr_fd("unknown error", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
