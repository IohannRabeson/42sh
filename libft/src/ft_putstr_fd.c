/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 03:05:01 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 05:48:12 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <unistd.h>

void	ft_putstr_fd(char const *str, int fd)
{
	int const	happy_compiler = write(fd, str, ft_strlen(str));

	(void)happy_compiler;
}
