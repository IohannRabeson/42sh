/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:08:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 23:08:27 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int	path_is_lnk(char const *path)
{
	struct stat	buf;

	if (lstat(path, &buf) >= 0)
		return (S_ISLNK(buf.st_mode));
	else
		return (0);
}

int	path_is_dir(char const *path)
{
	struct stat	buf;

	if (lstat(path, &buf) >= 0)
		return (S_ISDIR(buf.st_mode));
	else
		return (0);
}

int	path_is_file(char const *path)
{
	struct stat	buf;

	if (lstat(path, &buf) >= 0)
		return (S_ISREG(buf.st_mode));
	else
		return (0);
}

int	path_is_relative(char const *path)
{
	return (path && path[0] != '/');
}

int	path_is_absolute(char const *path)
{
	return (path && path[0] == '/');
}
