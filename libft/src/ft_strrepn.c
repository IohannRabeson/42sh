/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:33:29 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:53:32 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str_buf.h"

char		*ft_strnrep(char const *origin, t_ui begin, t_ui size,
						char const *replacement)
{
	t_str_buf	buffer;
	char		*str;

	str_buf_init(&buffer);
	if (begin > 0)
		str_buf_app_strn(&buffer, origin, begin);
	str_buf_app_str(&buffer, replacement);
	if (ft_strlen(origin + size) > 0)
		str_buf_app_str(&buffer, origin + begin + size);
	str = str_buf_get(&buffer);
	str_buf_destroy(&buffer);
	return (str);
}
