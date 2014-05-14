/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:04:21 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 05:48:45 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putstrn_fd(char const *str, size_t n, int fd)
{
	int const	happy_compiler = write(fd, (void const *)str, n);

	(void)happy_compiler;
}
