/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:00:37 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 06:35:19 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str_buf.h>

char	*path_concat(char const *base, char const *append)
{
	t_str_buf	buf;
	char		*res;

	str_buf_init(&buf);
	str_buf_app_str(&buf, base);
	if (append && str_buf_get_last_char(&buf) != '/' && append[0] != '/')
		str_buf_app_char(&buf, '/');
	str_buf_app_str(&buf, append);
	res = str_buf_get(&buf);
	str_buf_destroy(&buf);
	return (res);
}
