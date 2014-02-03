/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 16:50:15 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/03 20:30:51 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include <ft_print.h>
#include <ft_getopt.h>
#include <ft_getopt_flag.h>
#include <ft_string.h>
#include <unistd.h>

static void	bt_env_exec_subcmd(t_cmd *cmd, t_env *env)
{
	/*t_getopt	getopt;
	t_go_flag	*gof;
	t_ui		i;

	i = 1;
	getopt_init(&getopt);
	// Parse options
	while (i < cmd->params_count)
	{
		gof = getopt_parse(&getopt, cmd->params[i], i);
		if (gof != NULL)
		{
			if (gof->type == GOFT_DASH && ft_strequ(gof->key, "-i"))
				env_clear(env);
			else
				break ;
		}
		++i;
	}
	// Parse key == value
	while (i < cmd->params_count)
	{
		gof = getopt_parse(&getopt, cmd->params[i], i);
		if (gof != NULL)
		{
			if (gof->type == GOFT_KEY_VALUE)
				env_set(env, gof->key, gof->value);
			else
				break ;
		}
		++i;
	}
	// Parse command
	t_list		cmd_args;
	
	list_init(&cmd_args, free);
	while (i < cmd->params_count)
	{
		list_push_back(&cmd_args, cmd->params[i]);
		++i;
	}
	list_destroy(&cmd_args);
	getopt_destroy(&getopt);
	*/
	/*
		Le principe en gros c'est de parcourir les lexems de la commandes(donc
		faut rajouter la listes des lexems de la commandes à t_cmd) jusqu'a ce
		qu'on trouve quelque chose qui n'est pas de la forme
		-<text> <text>=<text>, on considère que c'est le premier argument
		de la sous commande.
		Donc ensuite, on choppe tout les lexems à partir du premier argument
		et on les envoies dans la fonction
		app_process_all_cmd(app_process_line.c). Cette fonction devra devenir
		publique et changer de nom pour app_process_lexems.
	*/
	(void)cmd;
	(void)env;	
}

static void	bt_env_print_env(t_env const *env, int fd)
{
	t_env_var const	*it;
	t_env_var const	*end;

	it = env_cbegin(env);
	end = env_cend(env);
	while (it != end)
	{
		ft_putstr_fd(it->key, fd);
		ft_putchar_fd('=', fd);
		ft_putendl_fd(it->value, fd);
		++it;
	}
}

void		bt_env(t_cmd *cmd, t_env const *env)
{
	t_env	env_cpy;

	env_init(&env_cpy, NULL);
	env_copy(&env_cpy, env);
	if (cmd->argc == 1)
		bt_env_print_env(env, STDOUT_FILENO);
	else
		bt_env_exec_subcmd(cmd, &env_cpy);
	env_destroy(&env_cpy);
}
