/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 20:39:03 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 06:47:39 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "app.h"
#include <ft_print.h>
#include <ft_string.h>
#include <ft_format.h>

static void	print_histo_item(t_ui i, char const *str)
{
	char					*temp;
	char					*aligned;

	temp = ft_uitoa(i);
	if (temp)
	{
		aligned = ft_format_align(temp, 4, AL_RIGHT);
		if (aligned)
		{
			ft_putstr(aligned);
			ft_putstr(" - ");
			ft_putendl(str);
			free(aligned);
		}
		free(temp);
	}
}

static void	print_history(void)
{
	t_app const	*const		app = app_instance();
	t_histo	const *const	histo = &app->histo;

	histo_cforeach(histo, print_histo_item);
}

static void	remove_item_history(t_cmd const *cmd)
{
	t_app *const	app = app_instance();
	int				item_index;

	item_index = -1;
	if (cmd->argc > 2)
	{
		item_index = ft_atoi(cmd->args[2]);
	}
	else
	{
		cmd_errorl(cmd, 1, "usage: history -d <entry_id>");
		return ;
	}
	if (item_index < 0 || item_index >= (int)histo_size(&app->histo))
	{
		cmd_errorl(cmd, 1, "invalid history item's index");
		return ;
	}
	histo_remove(&app->histo, item_index);
}

static void	reload_history(void)
{
	histo_load_config(&app_instance()->histo, FILE_HISTORY);
}

void		bt_history(t_cmd *cmd, struct s_env *env)
{
	t_app *const	app = app_instance();
	t_getopt		go;

	if (cmd->argc == 1)
	{
		print_history();
		return ;
	}
	getopt_init_args(&go, cmd->argc, cmd->args);
	if (getopt_contains(&go, "-c"))
		histo_clear(&app->histo);
	else if (getopt_contains(&go, "-d"))
		remove_item_history(cmd);
	else if (getopt_contains(&go, "-r"))
		reload_history();
	getopt_destroy(&go);
	(void)env;
}
