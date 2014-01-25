/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 01:23:57 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 19:24:47 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_BUILDER_H
# define CMD_BUILDER_H

# include "lexem.h"

struct			s_cmd;
struct			s_list_node;

struct s_list_node	*cmd_bld_build(struct s_cmd *cmd,
								   struct s_list_node *lex_it);
struct s_list_node	*cmd_bld_setup_params(struct s_cmd *cmd,
										  struct s_list_node *lex_it);
struct s_list_node	*cmd_bld_setup_operators(struct s_cmd *cmd,
											 struct s_list_node *lex_it);
#endif
