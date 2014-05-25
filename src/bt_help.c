/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 04:14:27 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 09:16:01 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "app.h"
#include <ft_print.h>
#include <ft_str_array.h>
#include <ft_string.h>

static char const	*g_msg[] =
{
	"builtin not found",
	"désolé ce builtin n'a pas été trouvé",
	"non, je trouve vraiment pas",
	"je te dis que ça n'existe pas",
	"wesh vas-y tu minaude quoi là!",
	"ma gueule t'écrit n'imp'",
	"toi même tu sais qu'c'est nawak",
	"effectivement t'as besoin d'aide",
	"kamoulox",
	NULL
};

static void	help_summary(void)
{
	t_app const *const	app = app_instance();
	t_ui				i;

	i = 0;
	ft_putendl("Available builtins (type help <builtin name> for details):");
	while (i < app->builtins.size)
	{
		ft_putstr("    ");
		ft_putendl(app->builtins.builtins[i].key);
		++i;
	}
}

static void	help_detailed(t_cmd const *cmd)
{
	t_ui const			g_msg_count = str_array_size((char **)g_msg);
	t_builtin const		*builtin;
	char				*topic;
	t_ui				k;

	topic = cmd->args[1];
	builtin = builtins_find(&app_instance()->builtins, topic);
	if (builtin)
	{
		ft_putstr(builtin->key);
		ft_putstr(" ");
		ft_putendl(builtin->help);
	}
	else
	{
		k = ft_strlen(topic) + histo_size(&app_instance()->histo);
		cmd_errorl(cmd, 2, g_msg[k % g_msg_count]);
	}
}

void	bt_help(t_cmd *cmd, struct s_env *env)
{
	if (cmd->argc == 1)
		help_summary();
	else if (cmd->argc > 1)
		help_detailed(cmd);
	(void)cmd;
	(void)env;
}
