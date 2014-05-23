/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:23:34 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/23 17:06:45 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# include <ft_types_def.h>
# include <ft_list.h>

typedef struct	s_cmd
{
	char			**args;
	t_ui			argc;
	char			*in_file;
	char			*out_file;
	t_bool			trunc_out;
	struct s_cmd	*next;
}				t_cmd;

void			cmd_init(t_cmd *cmd);
void			cmd_destroy(t_cmd *cmd);
t_cmd			*cmd_malloc(void);
void			cmd_free(t_cmd *cmd);
void			cmd_exec(t_cmd *cmd, char **env);
int				cmd_exec_chain(t_cmd *it, char **env, int fd_in);
void			cmd_errorl(t_cmd const *cmd, t_ui level, char const *msg);
void			cmd_add_arg(t_cmd *cmd, char const *arg);
void			cmd_set_in_file(t_cmd *cmd, char const *filepath);
void			cmd_set_out_file(t_cmd *cmd, char const *filepath,
									t_bool trunc);
t_bool			build_redirects_in(t_cmd *cmd, t_list *cmd_lexems);
t_bool			build_redirects_out(t_cmd *cmd, t_list *cmd_lexems);
t_bool			build_redirects_outa(t_cmd *cmd, t_list *cmd_lexems);
t_bool			build_pipes(t_cmd *cmd, t_list *cmd_lexems);
void			build_args(t_cmd *cmd, t_list *cmd_lexems);

#endif
