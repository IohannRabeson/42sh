/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:16:33 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 22:43:41 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <stdio.h>

int	main(int argc, char **argv, char **environs)
{
	app_init(argc, argv, environs);
	app_destroy();
	return (0);
	(void)argc;
	(void)argv;
}