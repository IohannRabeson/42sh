/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:08:07 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/26 02:29:09 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		path_exists(char const *path)
{
	if (path && access(path, F_OK) == 0)
		return (1);
	else
		return (0);
}
