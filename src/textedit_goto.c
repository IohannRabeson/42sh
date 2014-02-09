/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit_goto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 21:12:04 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 21:12:13 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"

t_bool	textedit_can_goto(t_textedit const *te, t_ui buf_pos)
{
	if (buf_pos >= te->prompt.size
		&& buf_pos <= str_buf_size(&te->buffer) + te->prompt.size)
	{
		return (true);
	}
	else
		return (false);
}
