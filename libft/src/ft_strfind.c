/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:38:12 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/29 18:18:03 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_bool		ft_strfind(char const *str, char const *find,
					   t_ui *begin, t_ui *size)
{
	t_ui const	str_len = ft_strlen(str);
	t_ui const	find_len = ft_strlen(find);
	t_ui		i;
	t_ui		j;

	i = 0;
	j = 0;
	*size = 0;
	if (str_len == 0 || find_len == 0)
		return (false);
	while (i < str_len && str[i] && find[j] && str[i] != find[j])
		++i;
	if (str[i] != find[j])
		return (false);
	else
		*begin = i;
	while (i < str_len && j < find_len)
	{
		if (str[i] == find[j])
			++(*size);
		++i;
		++j;
	}
	return (*size > 0);
}
