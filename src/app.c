/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:17:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 15:20:26 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_parser_trans const	g_parser_transitions[] =
{
	{ST_INIT, ST_SKIP_SPACES, CHRS_SPC},
	{ST_INIT, ST_PARAM, CHRS_LOW},
	{ST_INIT, ST_PARAM, CHRS_UPP},
	{ST_INIT, ST_PARAM, CHRS_DIG},
	{ST_INIT, ST_PARAM, CHRS_SID},
	{ST_INIT, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_INIT, ST_END_CMD, CHRS_CMD_END},
	{ST_SKIP_SPACES, ST_SKIP_SPACES, CHRS_SPC},
	{ST_SKIP_SPACES, ST_PARAM, CHRS_LOW},
	{ST_SKIP_SPACES, ST_PARAM, CHRS_UPP},
	{ST_SKIP_SPACES, ST_PARAM, CHRS_DIG},
	{ST_SKIP_SPACES, ST_PARAM, CHRS_SID},
	{ST_SKIP_SPACES, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_SKIP_SPACES, ST_END_CMD, CHRS_CMD_END},
	{ST_PARAM, ST_PARAM, CHRS_LOW},
	{ST_PARAM, ST_PARAM, CHRS_UPP},
	{ST_PARAM, ST_PARAM, CHRS_DIG},
	{ST_PARAM, ST_PARAM, CHRS_SID},
	{ST_PARAM, ST_SKIP_SPACES, CHRS_SPC},
	{ST_PARAM, ST_END_CMD, CHRS_CMD_END},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_SPC},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_LOW},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_UPP},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_DIG},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_SPE},
	{ST_DELIM_PARAM_IN, ST_DELIM_PARAM_OUT, CHRS_DELIM_PARAM},
	{ST_DELIM_PARAM_OUT, ST_SKIP_SPACES, CHRS_SPC},
	{ST_DELIM_PARAM_OUT, ST_END_CMD, CHRS_CMD_END},
	{ST_FPARAM, ST_FPARAM, CHRS_LOW},
	{ST_FPARAM, ST_FPARAM, CHRS_UPP},
	{ST_FPARAM, ST_FPARAM, CHRS_DIG},
	{ST_FPARAM, ST_FPARAM, CHRS_SPC},
	{ST_FPARAM, ST_FPARAM, CHRS_SPE},
	{ST_FPARAM, ST_DELIM_PARAM_OUT, CHRS_DELIM_PARAM},
	{ST_END_CMD, ST_END_CMD, CHRS_CMD_END},
	{ST_END_CMD, ST_SKIP_SPACES, CHRS_SPC},
	{ST_END_CMD, ST_PARAM, CHRS_LOW},
	{ST_END_CMD, ST_PARAM, CHRS_UPP},
	{ST_END_CMD, ST_PARAM, CHRS_DIG},
	{ST_END_CMD, ST_PARAM, CHRS_SID},
	{ST_END_CMD, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{PARSER_ERR_STATE, PARSER_ERR_STATE, NULL}
};

t_app	*app_instance(void)
{
	static t_app app;

	return (&app);
}

t_app	*app_init(int argc, char **argv, char **environs)
{
	t_app * const	app = app_instance();

	env_init(&app->env, environs);
	gnl_init(&app->gnl);
	parser_init(&app->parser, ST_INIT);
	parser_load(&app->parser, g_parser_transitions);
	app->run = true;
	return (app);
	(void)argv;
	(void)argc;
}

void	app_destroy(void)
{
	t_app * const	app = app_instance();

	parser_destroy(&app->parser);
	gnl_destroy(&app->gnl);
	env_destroy(&app->env);
}
