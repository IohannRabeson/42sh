/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 01:23:57 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 02:01:06 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_BUILDER_H
# define CMD_BUILDER_H

# include <ft_list.h>
# include "lexem.h"

struct			s_cmd;

typedef struct	s_cmd_bld
{
	
}				t_cmd_bld;

t_list_node	*cmd_bld_build(t_cmd_bld *builder,
						   struct s_cmd *cmd,
						   t_list_node *lex_it);

#endif
