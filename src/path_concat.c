/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:00:37 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 23:01:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*path_concat(char const *base_path, char const *appended)
{
	char	*path;
	size_t	base_len;
	size_t	app_len;
	size_t	total;

	if (base_path == NULL || appended == NULL)
		return (NULL);
	base_len = ft_strlen(base_path);
	app_len = ft_strlen(appended);
	total = base_len + app_len;
	if (base_len > 0 && base_path[base_len - 1] != '/')
		total += 1;
	path = (char *)malloc(sizeof(*path) * (total + 1));
	if (path == NULL)
		return (NULL);
	ft_strcpy(path, base_path);
	if (base_len > 0 && base_path[base_len - 1] != '/')
	{
		path[base_len] = '/';
		ft_strcpy(path + base_len + 1, appended);
	}
	else
		ft_strcpy(path + base_len, appended);
	return (path);
}
