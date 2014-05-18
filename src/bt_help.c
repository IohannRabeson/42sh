/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 04:14:27 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/18 04:20:06 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "app.h"
#include <ft_print.h>

void	bt_help(t_cmd *cmd, struct s_env *env)
{
	t_app const *const	app = app_instance();
	t_ui				i;

	i = 0;
	ft_putendl("Available builtins:");
	while (i < app->builtins.size)
	{
		ft_putstr("    ");
		ft_putendl(app->builtins.builtins[i].key);
		++i;
	}
	(void)cmd;
	(void)env;
}
