/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 03:26:18 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:40:08 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>
#include "ft_string.h"
#include "ft_memory.h"

static size_t	putnbr_count_digits(unsigned long n)
{
	size_t	result;

	result = 0;
	while (n != 0)
	{
		result += 1;
		n = n / 10;
	}
	return (result);
}

static char		*putnbr_itoa(unsigned long n, char *const buffer)
{
	size_t	count;
	size_t	i;
	char	*result;
	char	c;

	result = buffer;
	if (n == 0)
	{
		ft_strcpy(result, "0");
		return (result);
	}
	count = putnbr_count_digits(n);
	i = 1;
	while (n != 0)
	{
		c = '0' + (n % 10);
		result[count - i] = c;
		n = n / 10;
		i += 1;
	}
	result[count] = '\0';
	return (result);
}

void			ft_putul_fd(unsigned long n, int fd)
{
	char	temp[25];

	ft_memset(temp, '\0', 25);
	putnbr_itoa(n, temp);
	ft_putstr_fd(temp, fd);
}
