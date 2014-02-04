/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:26:37 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 03:11:44 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <ft_string.h>

void		cmd_set_in_file(t_cmd *cmd, char const *filepath)
{
	if (filepath)
		cmd->in_file = ft_strdup(filepath);
	else
		cmd->in_file = NULL;
}

void		cmd_set_out_file(t_cmd *cmd, char const *filepath, t_bool trunc)
{
	if (filepath)
	{
		cmd->out_file = ft_strdup(filepath);
		cmd->trunc_out = trunc;
	}
	else
		cmd->out_file = NULL;
}
