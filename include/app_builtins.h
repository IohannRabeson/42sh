/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_builtins.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:48:35 by irabeson          #+#    #+#             */
/*   Updated: 2014/06/18 07:32:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_BUILTINS_H
# define APP_BUILTINS_H

struct s_cmd;
struct s_env;

void	bt_exit(struct s_cmd *cmd, struct s_env *env);
void	bt_cd(struct s_cmd *cmd, struct s_env *env);
void	bt_env(struct s_cmd *cmd, struct s_env *env);
void	bt_setenv(t_cmd *cmd, struct s_env *env);
void	bt_unsetenv(t_cmd *cmd, struct s_env *env);
void	bt_help(t_cmd *cmd, struct s_env *env);
void	bt_history(t_cmd *cmd, struct s_env *env);
void	bt_echo(t_cmd *cmd, struct s_env *env);

#endif
