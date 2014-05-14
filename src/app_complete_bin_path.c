/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_complete_bin_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 00:38:50 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:06:19 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "path.h"
#include <ft_string.h>
#include <ft_str_array.h>
#include <stdlib.h>

static t_bool	check(char const *bin_path)
{
	return (path_exists(bin_path) && path_is_executable(bin_path));
}

char			*app_complete_bin_path(char const *bin_path)
{
	t_app const	*app;
	t_list		paths;
	t_list_node	*it;
	char		*temp;

	app = app_instance();
	if (check(bin_path))
		return (ft_strdup(bin_path));
	list_init(&paths, free);
	env_get_values(&app->env, "PATH", ':', &paths);
	it = paths.first;
	while (it && it->item)
	{
		temp = path_concat((char const *)it->item, bin_path);
		if (check(temp))
		{
			list_destroy(&paths);
			return (temp);
		}
		else
			free(temp);
		it = it->next;
	}
	list_destroy(&paths);
	return (NULL);
}
