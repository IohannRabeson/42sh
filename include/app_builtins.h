/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_builtins.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:48:35 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 20:49:08 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_BUILTINS_H
# define APP_BUILTINS_H

struct	s_cmd;
struct	s_env;

void	bt_exit(struct s_cmd *cmd, struct s_env const *env);

#endif
