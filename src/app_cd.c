/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 21:46:47 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:04:58 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "path.h"
#include <unistd.h>

t_bool	app_cd(char const *new_dir)
{
	t_app			*app;
	char const		*temp;

	app = app_instance();
	if (new_dir == NULL || path_exists(new_dir) == false || chdir(new_dir) != 0)
		return (false);
	temp = env_get_value(&app->env, "PWD");
	if (temp)
		env_set(&app->env, "OLDPWD", temp);
	env_set(&app->env, "PWD", new_dir);
	return (true);
}
