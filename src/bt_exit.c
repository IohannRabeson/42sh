/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:43:29 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/03 20:30:29 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "app.h"
#include <ft_string.h>

void	bt_exit(t_cmd *cmd, t_env const *env)
{
	int	ec;

	if (cmd->argc > 1)
		ec = ft_atoi(cmd->args[1]);
	else
		ec = 0;
	app_exit(ec);
	(void)cmd;
	(void)env;
}
