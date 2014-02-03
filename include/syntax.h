/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:56:11 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 00:19:36 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "lexem.h"
# include "app.h"
# include "cmd.h"
# include <ft_types_def.h>

void	extract_cmd(t_list *src, t_list *cmd_lexems);
t_bool	build_cmd(t_cmd *cmd, t_list *cmd_lexems);
t_bool	check_syntax(t_list const *cmd_lexems);

#endif
