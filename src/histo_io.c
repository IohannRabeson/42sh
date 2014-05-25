/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 04:39:13 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 07:10:47 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "histo.h"
#include "app.h"
#include "path.h"
#include <ft_list.h>
#include <ft_print.h>
#include <ft_str_buf.h>
#include <ft_string.h>
#include <ft_error.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static int	open_local(char const *path, int flags, mode_t mode)
{
	char	*new_path;
	int		res;

	res = -1;
	new_path = path_concat(app_instance()->app_path, path);
	if (new_path)
	{
		res = open(new_path, flags, mode);
		if (getopt_contains(&app_instance()->getopt, "--verbose"))
		{
			if (res >= 0)
				ft_putstr("open: ");
			else
				ft_putstr("open failed: ");
			ft_putendl(new_path);
			ft_putendl(path);
		}
		free(new_path);
	}
	return (res);
}

void		histo_save_config(t_histo *histo, char const *file_path)
{
	t_list_node	*it;
	char const	*line;
	int			fd;

	fd = open_local(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		ft_putendl_fd("ft_sh: failed to save history", 2);
		return ;
	}
	it = list_first(&histo->str_list);
	while (it)
	{
		line = (char const *)it->item;
		ft_putendl_fd(line, fd);
		it = it->next;
	}
}

void		histo_load_config(t_histo *histo, char const *file_path)
{
	int			fd;
	t_str_buf	str_buf;
	char		*content;

	
	list_clear(&histo->str_list);
	fd = open_local(file_path, O_RDONLY, 0);
	if (fd > 2)
	{
		str_buf_init(&str_buf);
		if (str_buf_read(&str_buf, fd) > 0)
		{
			content = str_buf_get(&str_buf);
			if (content)
			{
				ft_strsplit_list(content, '\n', &histo->str_list);
				free(content);
			}
		}
		str_buf_destroy(&str_buf);
	}
	else
		ft_putendl_fd("ft_sh: failed to load history", 2);
	close(fd);
}
