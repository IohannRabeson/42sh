/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:15:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 01:40:26 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H
# include <unistd.h>
# include <ft_types_def.h>
# include <ft_get_next_line.h>
# include <ft_getopt.h>
# include "env.h"
# include "parser.h"
# include "builtins.h"
# include "cmd.h"
# include "textedit.h"
# include "histo.h"
# include "keymapper.h"

# define CHRS_SPC				" \t\v\n\r\b"
# define CHRS_LOW				"abcdefghijklmnopqrstuvwxyz"
# define CHRS_UPP				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define CHRS_DIG				"0123456789"
# define CHRS_SID				"!#$%&()*+,-./:=?@[]^_{}~"
# define CHRS_SPE				"!#$%&()*+,-./:;<=>?@[]^_{|}~"
# define CHRS_DELIM_PARAM		"\""
# define CHRS_CMD_END			";"
# define CHRS_OPR_OUT			">"
# define CHRS_OPR_IN			"<"
# define CHRS_OP_PIPE			"|"
# define KW_REDIR_OUT_APP		">>"
# define KW_REDIR_IN_APP		"<<"
# define STR_PROMPT				"$> "
# define STR_APPNAME			"ft_sh"

typedef enum	e_parser_states
{
	ST_INIT = 0,
	ST_SKIP_SPACES,
	ST_PARAM,
	ST_FPARAM,
	ST_DELIM_PARAM_IN,
	ST_DELIM_PARAM_OUT,
	ST_END_CMD,
	ST_OP_REDIR_OUT,
	ST_OP_REDIR_OUTA,
	ST_OP_REDIR_IN,
	ST_OP_PIPE
}				t_parser_states;


typedef struct	s_app
{
	t_getopt	getopt;
	t_env		env;
	t_gnl		gnl;
	t_parser	parser;
	t_builtins	builtins;
	t_bool		run;
	int			exit_code;
	pid_t		current_cmd;
	t_textedit	textedit;
	t_histo		histo;
	t_keymapper	keymapper;
}				t_app;

t_app		*app_instance(void);
t_app		*app_init(int argc, char **argv, char **environs);
void		app_destroy(void);
char		*app_readline(void);
t_bool		app_process_line(char const *line);
void		app_process_lexems(t_list *lexems);
t_bool		app_process_cmd(struct s_cmd *cmd, t_env *env);
t_bool		app_process_builtin(t_cmd *cmd, t_env *env);
void		app_stop(void);
void		app_exit(int code);
t_bool		app_run(void);
t_bool		app_cd(char const *new_dir);
char		*app_complete_bin_path(char const *bin_path);
void		app_kill_cmd(int sig);

#endif
