/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:16:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:26:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "parser.h"
#include <ft_list.h>
#include <ft_print.h>
#include <ft_string.h>
#include <unistd.h>
#include <stdio.h>
#include <ft_str_array.h>

int	main(int argc, char **argv, char **environs)
{
	app_init(argc, argv, environs);
	while (app_run());

	char	**str;

	str = str_array_from_array(argc, argv);
	str_array_free(str);

	app_destroy();
	return (0);
}
