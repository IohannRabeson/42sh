/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 01:31:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 19:22:10 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_builder.h"
#include "lexem.h"
#include "app.h"
#include "cmd.h"
#include "path.h"
#include "app_lexems.h"
#include <ft_str_array.h>
#include <ft_string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*
**	Builds a t_cmd instance with the lexems list.
*/
t_list_node	*cmd_bld_build(t_cmd *cmd, t_list_node *lex_it)
{
	if (lex_it == NULL)
		return (NULL);
	lex_it = cmd_bld_setup_params(cmd, lex_it);
	if (lex_it == NULL)
		return (NULL);
	lex_it = cmd_bld_setup_operators(cmd, lex_it);
	return (lex_it);
}
