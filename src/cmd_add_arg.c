/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:22:14 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 01:17:28 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <ft_str_array.h>
#include <ft_string.h>
#include <ft_error.h>

void		cmd_add_arg(t_cmd *cmd, char const *arg)
{
	cmd->args = str_array_append(cmd->args, arg);
	cmd->argc = str_array_size(cmd->args);
}
