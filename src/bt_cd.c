/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 21:13:15 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:34:10 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "app.h"
#include "path.h"
#include <ft_list.h>
#include <ft_string.h>
#include <ft_str_buf.h>
#include <ft_error.h>

static t_list_node	*process_part(t_list *sp_pwd, t_list *sp_nav,
									t_list_node *nav_it)
{
	char const	*home;
	char		*nav;

	home = env_get_value(&app_instance()->env, "HOME");
	if (nav_it == NULL || home == NULL)
		return (NULL);
	nav = (char *)nav_it->item;
	if (ft_strequ(nav, "."))
		nav_it = list_erase(sp_nav, nav_it);
	else if (ft_strequ(nav, ".."))
	{
		list_pop_back(sp_pwd);
		nav_it = nav_it->next;
	}
	else if (ft_strequ(nav, "~"))
	{
		list_push_back(sp_pwd, (void *)ft_strdup(home));
		nav_it = nav_it->next;
	}
	else
	{
		list_push_back(sp_pwd, (void *)ft_strdup(nav));
		nav_it = nav_it->next;
	}
	return (nav_it);
}

static char			*recompose(t_list const *splitted_path)
{
	t_list_node const	*it;
	t_str_buf			strbuf;
	char const			*part;
	char				*results;

	str_buf_init(&strbuf);
	it = list_cfirst(splitted_path);
	while (it)
	{
		part = (char const *)it->item;
		if (it == list_cfirst(splitted_path)
			|| (part[0] != '/' && str_buf_get_last_char(&strbuf) != '/'))
			str_buf_app_char(&strbuf, '/');
		if (part)
		{
			str_buf_app_str(&strbuf, part);
			str_buf_app_char(&strbuf, '/');
		}
		it = it->next;
	}
	results = str_buf_get(&strbuf);
	str_buf_destroy(&strbuf);
	return (results);
}

static char			*make_path(char const *nav, char const *pwd)
{
	t_list		sp_pwd;
	t_list		sp_nav;
	t_list_node	*nav_it;
	char		*results;

	list_init(&sp_pwd, free);
	list_init(&sp_nav, free);
	ft_strsplit_list(pwd, '/', &sp_pwd);
	ft_strsplit_list(nav, '/', &sp_nav);
	nav_it = sp_nav.first;
	if (path_is_absolute(nav))
		list_clear(&sp_pwd);
	while (nav_it)
		nav_it = process_part(&sp_pwd, &sp_nav, nav_it);
	results = recompose(&sp_pwd);
	list_destroy(&sp_pwd);
	list_destroy(&sp_nav);
	return (results);
}

static t_bool		change_cd(char const *cmd, char const *pwd)
{
	char	*new_path;
	t_bool	result;

	result = false;
	new_path = make_path(cmd, pwd);
	if (new_path)
	{
		result = app_cd(new_path);
		free(new_path);
	}
	return (result);
}

void				bt_cd(t_cmd *cmd, t_env *env)
{
	char const	*pwd;
	t_bool		result;

	pwd = env_get_value(env, "PWD");
	if (pwd == NULL)
	{
		cmd_errorl(cmd, 2, "no valid environ");
		return ;
	}
	if (cmd->argc == 1 || cmd->args[1] == NULL)
		result = app_cd(env_get_value(env, "HOME"));
	else if (ft_strequ(cmd->args[1], "-"))
		result = app_cd(env_get_value(env, "OLDPWD"));
	else
		result = change_cd(cmd->args[1], pwd);
	if (result == false)
		cmd_errorl(cmd, 2, "no such a directory");
}
