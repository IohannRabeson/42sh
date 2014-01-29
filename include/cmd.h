/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:01:17 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/27 22:38:23 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# include <ft_types_def.h>
# include <sys/types.h>

struct			s_env;
struct			s_list;
struct			s_app;
struct			s_builtin;

typedef enum	e_cmd_type
{
	CMD_BUILTIN = 0,
	CMD_EXE,
	CMD_UNKNOW,
	CMD_ERROR,
	CMD_COUNT
}				t_cmd_type;

typedef enum	e_cmd_mode
{
	CMD_MODE_NORMAL = 0,
	CMD_MODE_REDIR_OUT,
	CMD_MODE_REDIR_OUTA,
	CMD_MODE_REDIR_IN,
	CMD_MODE_PIPE,
	CMD_MODE_COUNT
}				t_cmd_mode;

typedef struct	s_cmd
{
	t_cmd_type		type;
	t_cmd_mode		mode;
	char			**params;
	t_ui			params_count;
	char			*filename;
	struct s_buitin	*builtin;
	t_bool			success;
	pid_t			pid;
}				t_cmd;

typedef	t_bool(*t_cmd_exec_func)(t_cmd *, struct s_env const *);

void	cmd_init(t_cmd *cmd);
void	cmd_destroy(t_cmd *cmd);
t_bool	cmd_is_exec(t_cmd const *cmd);
t_bool	cmd_is_builtin(t_cmd const *cmd);
t_bool	cmd_exec(t_cmd *cmd, struct s_env const *env);
t_bool	cmd_exec_builtin(t_cmd *cmd, struct s_env const *env);
t_bool	cmd_exec_simple(t_cmd *cmd, struct s_env const *env);
t_bool	cmd_exec_redir_out(t_cmd *cmd, struct s_env const *env);
t_bool	cmd_exec_redir_in(t_cmd *cmd, struct s_env const *env);
t_bool	cmd_exec_open_ofile(t_cmd *cmd, int *fd_out);
t_bool	cmd_exec_open_ifile(t_cmd *cmd, int *fd_in);
void	cmd_error(t_cmd const *cmd, char const *msg);
void	cmd_errorl(t_cmd const *cmd, t_ui level, char const *msg);

#endif
