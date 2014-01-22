/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_can.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:00:18 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 23:00:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int		path_can_be_executed(char const *path)
{
	struct stat	s;

	if (lstat(path, &s) < 0)
		return (0);
	return (s.st_mode & S_IXUSR);
}
