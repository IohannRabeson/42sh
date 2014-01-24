/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:01:17 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 18:19:17 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# include <ft_types_def.h>

struct			s_env;
struct			s_list;
struct			s_app;

typedef enum	e_cmd_type
{
	CMD_BUILTIN = 0,
	CMD_EXE,
	CMD_UNKNOW,
	CMD_COUNT
}				t_cmd_type;

typedef struct	s_cmd
{
	t_cmd_type	type;
	char		**params;
	int			fd_in;
	int			fd_out;
	t_bool		success;
}				t_cmd;

void	cmd_init(t_cmd *cmd);
void	cmd_destroy(t_cmd *cmd);
void	cmd_setup(t_cmd *cmd,
				  struct s_list const *params,
				  struct s_app const *app);
t_bool	cmd_exec(t_cmd *cmd, struct s_env const *env);

#endif
