/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 16:50:15 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 04:51:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cmd.h"
#include "env.h"
#include "app.h"
#include <ft_print.h>
#include <ft_getopt.h>
#include <ft_getopt_flag.h>
#include <ft_string.h>
#include <unistd.h>

static void	bt_env_exec_subcmd(t_cmd *cmd, t_env *env)
{
	t_cmd	sub_cmd;

	sub_cmd = *cmd;
	++sub_cmd.args;
	--sub_cmd.argc;
	app_process_cmd(&sub_cmd, env);
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

void		bt_env(t_cmd *cmd, t_env *env)
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
