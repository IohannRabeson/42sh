/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 19:08:18 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 19:21:42 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textedit.h"
#include <ft_string.h>

char	*textedit_get_text(t_textedit const *te)
{
	t_str_buf	temp;
	char		*str;

	if (str_buf_size(&te->buffer) == te->prompt.size)
		return (NULL);
	str_buf_init(&temp);
	str_buf_clone(&temp, &te->buffer);
	str_buf_erase(&temp, 0, te->prompt.size);
	str = str_buf_get(&temp);
	str_buf_destroy(&temp);
	return (str);
}
