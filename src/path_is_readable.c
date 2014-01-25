/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_is_readable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:20:20 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 18:24:59 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include <sys/stat.h>

t_bool	path_is_readable(char const *path)
{
	struct stat	s;

	if (lstat(path, &s) < 0)
		return (0);
	return (s.st_mode & S_IRUSR);
}
