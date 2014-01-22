/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:16:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 14:12:26 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <ft_list.h>
#include <unistd.h>
#include <ft_print.h>
#include <ft_string.h>
#include <ft_memory.h>
#include <ft_get_next_line.h>
#include <ft_str_array.h>

int	main(int argc, char **argv, char **environs)
{
	t_list	path;
	
	app_init(argc, argv, environs);
	list_init(&path, free);
	env_get_values(&app_instance()->env, "PATH", ':', &path);
	str_array_foreach(environs, ft_putendl);
//	list_foreach(&path, ft_putendl);
	list_destroy(&path);
	app_destroy();
	return (0);
}
