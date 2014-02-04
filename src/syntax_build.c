/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 23:10:31 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 12:55:03 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include "cmd.h"
#include "lexems.h"
#include "app.h"

t_bool	build_redirects_in(t_cmd *cmd, t_list *cmd_lexems);
t_bool	build_redirects_out(t_cmd *cmd, t_list *cmd_lexems);
t_bool	build_redirects_outa(t_cmd *cmd, t_list *cmd_lexems);
t_bool	build_pipes(t_cmd *cmd, t_list *cmd_lexems);
void	build_args(t_cmd *cmd, t_list *cmd_lexems);

t_bool		build_cmd(t_cmd *cmd, t_list *cmd_lexems)
{
	if (build_redirects_in(cmd, cmd_lexems) == false)
		return (false);
	build_args(cmd, cmd_lexems);
	if (build_pipes(cmd, cmd_lexems) == false)
		return (false);
	if (build_redirects_out(cmd, cmd_lexems) == false)
		return (false);
	if (build_redirects_outa(cmd, cmd_lexems) == false)
		return (false);
	return (true);
}
