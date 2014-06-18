/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 07:32:17 by irabeson          #+#    #+#             */
/*   Updated: 2014/06/18 08:23:00 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include <ft_str_buf.h>
#include <ft_string.h>
#include <ft_memory.h>
#include <unistd.h>

static t_ui	imp_consume_flags(t_cmd *cmd, t_bool flags[2], t_ui i)
{
	ft_bzero(flags, sizeof(*flags) * 2);
	while (i < cmd->argc)
	{
		if (ft_strequ(cmd->args[i], "-n"))
			flags[0] = true;
		else if (ft_strequ(cmd->args[i], "-e"))
			flags[1] = true;
		else
			break ;
		++i;
	}
	return (i);
}

static void	imp_interprete_backslash(t_str_buf *strbuf)
{
	str_buf_replace_all(strbuf, "\\n", "\n");
	str_buf_replace_all(strbuf, "\\t", "\t");
}

void		bt_echo(t_cmd *cmd, struct s_env *env)
{
	t_ui		i;
	t_str_buf	strbuf;
	t_bool		flags[2];

	i = 1;
	str_buf_init(&strbuf);
	i = imp_consume_flags(cmd, flags, i);
	while (i < cmd->argc)
	{
		str_buf_app_str(&strbuf, cmd->args[i++]);
		if (i < cmd->argc)
			str_buf_app_char(&strbuf, ' ');
	}
	if (flags[1])
		imp_interprete_backslash(&strbuf);
	if (flags[0] == false)
		str_buf_app_char(&strbuf, '\n');
	str_buf_write(&strbuf, STDOUT_FILENO);
	str_buf_destroy(&strbuf);
	(void)env;
}
