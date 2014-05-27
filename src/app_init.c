/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 21:55:19 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/27 00:36:01 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "textedit.h"
#include "terminal.h"
#include "app_builtins.h"
#include "path.h"
#include "env.h"
#include <ft_string.h>
#include <ft_memory.h>
#include <ft_string.h>
#include <unistd.h>

static t_builtin const		g_builtins[] =
{
	{"exit", bt_exit, "exit [exit_code]"},
	{"cd", bt_cd, "cd [-]"},
	{"env", bt_env, "env [-i <exec>]"},
	{"setenv", bt_setenv, "setenv <key> [value]"},
	{"unsetenv", bt_unsetenv, "unsetenv <key>"},
	{"help", bt_help, "help [builtin]"},
	{"history", bt_history, "history [-c | -d <index> | -r]"},
	{NULL, NULL, NULL}
};

static const t_keymap		g_keymaps[] =
{
	{{10, 0, 0, 0}, textedit_validate},
	{{127, 0, 0, 0}, cursor_backspace},
	{{27, 91, 51, 126}, cursor_suppr},
	{{27, 91, 65, 0}, recall_prev},
	{{27, 91, 66, 0}, recall_next},
	{{27, 91, 68, 0}, cursor_prev_char},
	{{53, 67, 0, 0}, cursor_next_word},
	{{53, 68, 0, 0}, cursor_prev_word},
	{{27, 91, 67, 0}, cursor_next_char},
	{{0, 0, 0, 0}, NULL}
};

static t_parser_trans const	g_parser_transitions[] =
{
	{ST_INIT, ST_SKIP_SPACES, CHRS_SPC},
	{ST_INIT, ST_PARAM, CHRS_LOW},
	{ST_INIT, ST_PARAM, CHRS_UPP},
	{ST_INIT, ST_PARAM, CHRS_DIG},
	{ST_INIT, ST_PARAM, CHRS_SID},
	{ST_INIT, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_INIT, ST_END_CMD, CHRS_CMD_END},
	{ST_INIT, ST_OP_REDIR_OUT, CHRS_OPR_OUT},
	{ST_INIT, ST_OP_REDIR_IN, CHRS_OPR_IN},
	
	{ST_SKIP_SPACES, ST_SKIP_SPACES, CHRS_SPC},
	{ST_SKIP_SPACES, ST_PARAM, CHRS_LOW},
	{ST_SKIP_SPACES, ST_PARAM, CHRS_UPP},
	{ST_SKIP_SPACES, ST_PARAM, CHRS_DIG},
	{ST_SKIP_SPACES, ST_PARAM, CHRS_SID},
	{ST_SKIP_SPACES, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_SKIP_SPACES, ST_END_CMD, CHRS_CMD_END},
	{ST_SKIP_SPACES, ST_OP_REDIR_OUT, CHRS_OPR_OUT},
	{ST_SKIP_SPACES, ST_OP_REDIR_IN, CHRS_OPR_IN},
	{ST_SKIP_SPACES, ST_OP_PIPE, CHRS_OP_PIPE},
	{ST_SKIP_SPACES, ST_OP_AND_1, CHRS_OP_AND},
	{ST_PARAM, ST_PARAM, CHRS_LOW},
	{ST_PARAM, ST_PARAM, CHRS_UPP},
	{ST_PARAM, ST_PARAM, CHRS_DIG},
	{ST_PARAM, ST_PARAM, CHRS_SID},
	{ST_PARAM, ST_SKIP_SPACES, CHRS_SPC},
	{ST_PARAM, ST_END_CMD, CHRS_CMD_END},
	{ST_PARAM, ST_OP_REDIR_OUT, CHRS_OPR_OUT},
	{ST_PARAM, ST_OP_REDIR_IN, CHRS_OPR_IN},
	{ST_PARAM, ST_OP_PIPE, CHRS_OP_PIPE},

	{ST_PARAM, ST_OP_ASSIGN, CHRS_OP_ASSIGN},
	{ST_PARAM, ST_OP_AND_1, CHRS_OP_AND},

	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_SPC},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_LOW},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_UPP},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_DIG},
	{ST_DELIM_PARAM_IN, ST_FPARAM, CHRS_SPE},
	{ST_DELIM_PARAM_IN, ST_DELIM_PARAM_OUT, CHRS_DELIM_PARAM},
	{ST_DELIM_PARAM_OUT, ST_SKIP_SPACES, CHRS_SPC},
	{ST_DELIM_PARAM_OUT, ST_END_CMD, CHRS_CMD_END},
	{ST_DELIM_PARAM_OUT, ST_OP_PIPE, CHRS_OP_PIPE},

	{ST_DELIM_PARAM_OUT, ST_OP_ASSIGN, CHRS_OP_ASSIGN},
	{ST_DELIM_PARAM_OUT, ST_OP_AND_1, CHRS_OP_AND},

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
	{ST_END_CMD, ST_OP_REDIR_OUT, CHRS_OPR_OUT},
	{ST_END_CMD, ST_OP_REDIR_IN, CHRS_OPR_IN},
	{ST_OP_REDIR_OUT, ST_SKIP_SPACES, CHRS_SPC},
	{ST_OP_REDIR_OUT, ST_PARAM, CHRS_LOW},
	{ST_OP_REDIR_OUT, ST_PARAM, CHRS_UPP},
	{ST_OP_REDIR_OUT, ST_PARAM, CHRS_DIG},
	{ST_OP_REDIR_OUT, ST_PARAM, CHRS_SID},
	{ST_OP_REDIR_OUT, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_OP_REDIR_OUT, ST_OP_REDIR_OUTA, CHRS_OPR_OUT},
	{ST_OP_REDIR_OUTA, ST_SKIP_SPACES, CHRS_SPC},
	{ST_OP_REDIR_OUTA, ST_PARAM, CHRS_LOW},
	{ST_OP_REDIR_OUTA, ST_PARAM, CHRS_UPP},
	{ST_OP_REDIR_OUTA, ST_PARAM, CHRS_DIG},
	{ST_OP_REDIR_OUTA, ST_PARAM, CHRS_SID},
	{ST_OP_REDIR_OUTA, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_OP_REDIR_IN, ST_SKIP_SPACES, CHRS_SPC},
	{ST_OP_REDIR_IN, ST_PARAM, CHRS_LOW},
	{ST_OP_REDIR_IN, ST_PARAM, CHRS_UPP},
	{ST_OP_REDIR_IN, ST_PARAM, CHRS_DIG},
	{ST_OP_REDIR_IN, ST_PARAM, CHRS_SID},
	{ST_OP_REDIR_IN, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_OP_PIPE, ST_SKIP_SPACES, CHRS_SPC},
	{ST_OP_PIPE, ST_PARAM, CHRS_LOW},
	{ST_OP_PIPE, ST_PARAM, CHRS_UPP},
	{ST_OP_PIPE, ST_PARAM, CHRS_DIG},
	{ST_OP_PIPE, ST_PARAM, CHRS_SID},
	{ST_OP_PIPE, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_OP_PIPE, ST_OP_OR, CHRS_OP_PIPE},

	{ST_OP_ASSIGN, ST_SKIP_SPACES, CHRS_SPC},
	{ST_OP_ASSIGN, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_OP_ASSIGN, ST_PARAM, CHRS_LOW},
	{ST_OP_ASSIGN, ST_PARAM, CHRS_UPP},
	{ST_OP_ASSIGN, ST_PARAM, CHRS_DIG},
	{ST_OP_ASSIGN, ST_PARAM, CHRS_SID},

	{ST_OP_OR, ST_SKIP_SPACES, CHRS_SPC},
	{ST_OP_OR, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_OP_OR, ST_PARAM, CHRS_LOW},
	{ST_OP_OR, ST_PARAM, CHRS_UPP},
	{ST_OP_OR, ST_PARAM, CHRS_DIG},
	{ST_OP_OR, ST_PARAM, CHRS_SID},

	{ST_OP_AND_1, ST_OP_AND, CHRS_OP_AND},

	{ST_OP_AND, ST_SKIP_SPACES, CHRS_SPC},
	{ST_OP_AND, ST_DELIM_PARAM_IN, CHRS_DELIM_PARAM},
	{ST_OP_AND, ST_PARAM, CHRS_LOW},
	{ST_OP_AND, ST_PARAM, CHRS_UPP},
	{ST_OP_AND, ST_PARAM, CHRS_DIG},
	{ST_OP_AND, ST_PARAM, CHRS_SID},

	{PARSER_ERR_STATE, PARSER_ERR_STATE, NULL}
};

static void	user_validate(char const *str)
{
	t_app	*app;

	app = app_instance();
	if (str && ft_strlen(str) > 0)
	{
		terminal_putchar('\n');
		terminal_destroy();
		if (app_process_line(str))
		{
			histo_push(&app->histo, str);
		}
		terminal_init();
	}
}

static void	init_gui(t_app *app)
{
	terminal_init();
	terminal_exec("cl");
	textedit_init(&app->textedit, STR_PROMPT, user_validate);
	histo_init(&app->histo);
	histo_load_config(&app->histo, FILE_HISTORY);
	keymapper_init(&app->keymapper);
	keymapper_load(&app->keymapper, g_keymaps);
}

static void	init_variables(t_app *app)
{
	char	*pid_str;

	pid_str = ft_ultoa(getpid());
	env_set(&app->vars, "$?", "0");
	if (pid_str)
	{
		env_set(&app->vars, "$$", pid_str);
		free(pid_str);
	}
}

t_app		*app_init(int argc, char **argv, char **environs)
{
	t_app	*app;

	app = app_instance();
	ft_bzero(app, sizeof(*app));
	getopt_init_args(&app->getopt, argc, argv);
	env_init(&app->env, environs);
	env_init(&app->vars, NULL);
	init_variables(app);
	app->app_path = ft_strdup("./");
	gnl_init(&app->gnl);
	parser_init(&app->parser, ST_INIT);
	app->parser.verbose = getopt_contains(&app->getopt, "--verbose");
	parser_load(&app->parser, g_parser_transitions);
	builtins_init(&app->builtins);
	builtins_load(&app->builtins, g_builtins);
	app->run = true;
	init_gui(app);
	return (app);
}
