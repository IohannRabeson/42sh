/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 03:22:58 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:25:08 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_bool	cmd_is_exec(t_cmd const *cmd)
{
	return (cmd && cmd->type == CMD_EXE);
}

t_bool	cmd_is_builtin(t_cmd const *cmd)
{
	return (cmd && cmd->type == CMD_BUILTIN);
}
