/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:17:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 21:53:43 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "builtin.h"
#include "app_builtins.h"
#include <ft_memory.h>

t_builtin const			g_builtins[] =
{
	{"exit", bt_exit},
	{"cd", bt_cd},
	{NULL, NULL}
};

t_parser_trans const	g_parser_transitions[] =
{ 
	{PTT_CHARS, ST_INIT, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_INIT, ST_PARAM, CHRS_LOW},
	{PTT_CHARS, ST_INIT, ST_PARAM, CHRS_UPP},
	{PTT_CHARS, ST_INIT, ST_PARAM, CHRS_DIG},
	{PTT_CHARS, ST_INIT, ST_PARAM, CHRS_SID},
	{PTT_CHARS, ST_INIT, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{PTT_CHARS, ST_INIT, ST_END_CMD, CHRS_CMD_END},
	{PTT_CHARS, ST_INIT, ST_OP_REDIR_OUT, CHRS_OPR_OUT},
	{PTT_CHARS, ST_INIT, ST_OP_REDIR_IN, CHRS_OPR_IN},
	{PTT_CHARS, ST_SKIP_SPACES, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_SKIP_SPACES, ST_PARAM, CHRS_LOW},
	{PTT_CHARS, ST_SKIP_SPACES, ST_PARAM, CHRS_UPP},
	{PTT_CHARS, ST_SKIP_SPACES, ST_PARAM, CHRS_DIG},
	{PTT_CHARS, ST_SKIP_SPACES, ST_PARAM, CHRS_SID},
	{PTT_CHARS, ST_SKIP_SPACES, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{PTT_CHARS, ST_SKIP_SPACES, ST_END_CMD, CHRS_CMD_END},
	{PTT_CHARS, ST_SKIP_SPACES, ST_OP_REDIR_OUT, CHRS_OPR_OUT},
	{PTT_CHARS, ST_SKIP_SPACES, ST_OP_REDIR_IN, CHRS_OPR_IN},
	{PTT_CHARS, ST_PARAM, ST_PARAM, CHRS_LOW},
	{PTT_CHARS, ST_PARAM, ST_PARAM, CHRS_UPP},
	{PTT_CHARS, ST_PARAM, ST_PARAM, CHRS_DIG},
	{PTT_CHARS, ST_PARAM, ST_PARAM, CHRS_SID},
	{PTT_CHARS, ST_PARAM, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_PARAM, ST_END_CMD, CHRS_CMD_END},
	{PTT_CHARS, ST_PARAM, ST_OP_REDIR_OUT, CHRS_OPR_OUT},
	{PTT_CHARS, ST_PARAM, ST_OP_REDIR_IN, CHRS_OPR_IN},
	{PTT_CHARS, ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_SPC},
	{PTT_CHARS, ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_LOW},
	{PTT_CHARS, ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_UPP},
	{PTT_CHARS, ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_DIG},
	{PTT_CHARS, ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_SPE},
	{PTT_CHARS, ST_DELIM_PARAM_IN, ST_DELIM_PARAM_OUT, CHRS_DELIM_PARAM},
	{PTT_CHARS, ST_DELIM_PARAM_OUT, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_DELIM_PARAM_OUT, ST_END_CMD, CHRS_CMD_END},
	{PTT_CHARS, ST_FPARAM, ST_FPARAM, CHRS_LOW},
	{PTT_CHARS, ST_FPARAM, ST_FPARAM, CHRS_UPP},
	{PTT_CHARS, ST_FPARAM, ST_FPARAM, CHRS_DIG},
	{PTT_CHARS, ST_FPARAM, ST_FPARAM, CHRS_SPC},
	{PTT_CHARS, ST_FPARAM, ST_FPARAM, CHRS_SPE},
	{PTT_CHARS, ST_FPARAM, ST_DELIM_PARAM_OUT, CHRS_DELIM_PARAM},
	{PTT_CHARS, ST_END_CMD, ST_END_CMD, CHRS_CMD_END},
	{PTT_CHARS, ST_END_CMD, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_END_CMD, ST_PARAM, CHRS_LOW},
	{PTT_CHARS, ST_END_CMD, ST_PARAM, CHRS_UPP},
	{PTT_CHARS, ST_END_CMD, ST_PARAM, CHRS_DIG},
	{PTT_CHARS, ST_END_CMD, ST_PARAM, CHRS_SID},
	{PTT_CHARS, ST_END_CMD, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{PTT_CHARS, ST_END_CMD, ST_OP_REDIR_OUT, CHRS_OPR_OUT},
	{PTT_CHARS, ST_END_CMD, ST_OP_REDIR_IN, CHRS_OPR_IN},
	{PTT_CHARS, ST_OP_REDIR_OUT, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_OP_REDIR_OUT, ST_PARAM, CHRS_LOW},
	{PTT_CHARS, ST_OP_REDIR_OUT, ST_PARAM, CHRS_UPP},
	{PTT_CHARS, ST_OP_REDIR_OUT, ST_PARAM, CHRS_DIG},
	{PTT_CHARS, ST_OP_REDIR_OUT, ST_PARAM, CHRS_SID},
	{PTT_CHARS, ST_OP_REDIR_OUT, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{PTT_CHARS, ST_OP_REDIR_OUT, ST_OP_REDIR_OUTA, CHRS_OPR_OUT},
	{PTT_CHARS, ST_OP_REDIR_OUTA, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_OP_REDIR_OUTA, ST_PARAM, CHRS_LOW},
	{PTT_CHARS, ST_OP_REDIR_OUTA, ST_PARAM, CHRS_UPP},
	{PTT_CHARS, ST_OP_REDIR_OUTA, ST_PARAM, CHRS_DIG},
	{PTT_CHARS, ST_OP_REDIR_OUTA, ST_PARAM, CHRS_SID},
	{PTT_CHARS, ST_OP_REDIR_OUTA, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{PTT_CHARS, ST_OP_REDIR_IN, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_OP_REDIR_IN, ST_PARAM, CHRS_LOW},
	{PTT_CHARS, ST_OP_REDIR_IN, ST_PARAM, CHRS_UPP},
	{PTT_CHARS, ST_OP_REDIR_IN, ST_PARAM, CHRS_DIG},
	{PTT_CHARS, ST_OP_REDIR_IN, ST_PARAM, CHRS_SID},
	{PTT_CHARS, ST_OP_REDIR_IN, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{PTT_CHARS, ST_OP_REDIR_IN, ST_OP_REDIR_INA, CHRS_OPR_IN},
	{PTT_CHARS, ST_OP_REDIR_INA, ST_SKIP_SPACES, CHRS_SPC},
	{PTT_CHARS, ST_OP_REDIR_INA, ST_PARAM, CHRS_LOW},
	{PTT_CHARS, ST_OP_REDIR_INA, ST_PARAM, CHRS_UPP},
	{PTT_CHARS, ST_OP_REDIR_INA, ST_PARAM, CHRS_DIG},
	{PTT_CHARS, ST_OP_REDIR_INA, ST_PARAM, CHRS_SID},
	{PTT_CHARS, ST_OP_REDIR_INA, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{PTT_NULL, PARSER_ERR_STATE, PARSER_ERR_STATE, NULL}
};

t_app	*app_instance(void)
{ 
	static t_app app;

	return (&app);
}
t_app	*app_init(int argc, char **argv, char **environs)
{
	t_app * const	app = app_instance();

	ft_bzero(app, sizeof(*app));
	getopt_init_args(&app->getopt, argc, argv);
	env_init(&app->env, environs);
	gnl_init(&app->gnl);
	parser_init(&app->parser, ST_INIT);
	app->parser.verbose = getopt_contains(&app->getopt, "verbose");
	parser_load(&app->parser, g_parser_transitions);
	builtins_init(&app->builtins);
	builtins_load(&app->builtins, g_builtins);
	app->run = true;
	return (app);
}

void	app_destroy(void)
{
	t_app * const	app = app_instance();

	builtins_destroy(&app->builtins);
	parser_destroy(&app->parser);
	gnl_destroy(&app->gnl);
	env_destroy(&app->env);
	getopt_destroy(&app->getopt);
	ft_bzero(app, sizeof(*app));
}
