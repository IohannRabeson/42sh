/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:01:17 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 06:13:52 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# include <ft_types_def.h>
# include <sys/types.h>

struct			s_env;
struct			s_list;
struct			s_app;

typedef enum	e_cmd_type
{
	CMD_BUILTIN = 0,
	CMD_EXE,
	CMD_EXE_REDIR_OUT,
	CMD_EXE_REDIR_IN,
	CMD_UNKNOW,
	CMD_ERROR,
	CMD_COUNT
}				t_cmd_type;

typedef struct	s_cmd
{
	t_cmd_type	type;
	char		**params;
	int			fd_in;
	int			fd_out;
	t_bool		success;
	pid_t		pid;
}				t_cmd;

typedef	t_bool(*t_cmd_exec_func)(t_cmd *, struct s_env const *);

void	cmd_init(t_cmd *cmd);
void	cmd_destroy(t_cmd *cmd);
void	cmd_setup(t_cmd *cmd,
				  struct s_list const *params,
				  struct s_app const *app);
t_bool	cmd_exec(t_cmd *cmd, struct s_env const *env);
t_bool	cmd_is_exec(t_cmd const *cmd);
t_bool	cmd_exec_simple(t_cmd *cmd, struct s_env const *env);
t_bool	cmd_exec_redir_out(t_cmd *cmd, struct s_env const *env);
t_bool	cmd_exec_redir_in(t_cmd *cmd, struct s_env const *env);

#endif
