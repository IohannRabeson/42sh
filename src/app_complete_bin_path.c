/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_complete_bin_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 00:38:50 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 00:48:33 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "path.h"
#include <ft_string.h>

static t_bool	check(char const *bin_path)
{
	return (path_exists(bin_path) && path_is_executable(bin_path));
}

char		*app_complete_bin_path(char const *bin_path)
{
	t_app const * const	app = app_instance();
	char				**paths;
	char const			*path;
	char				**it;
	char				*temp;

	if (check(bin_path))
		return (ft_strdup(bin_path));
	path = env_get_value(&app->env, "PATH");
	if (path == NULL)
		return (NULL);
	paths = ft_strsplit(path, ':');
	it = paths;
	while (it && *it)
	{
		temp = path_concat(*it, bin_path);
		if (check(temp))
			return (temp);
		else
			free(temp);
		++it;
	}
	(void)bin_path;
	return (NULL);
}
