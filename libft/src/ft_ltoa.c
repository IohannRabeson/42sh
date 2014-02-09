/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 08:34:19 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:40:07 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

inline static size_t	count_digits(long n)
{
	size_t	result;

	if (n < 0)
		result = 1;
	else
		result = 0;
	while (n != 0)
	{
		result += 1;
		n = n / 10;
	}
	return (result);
}

inline static int		digit_abs(long n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

char					*ft_ltoa(long n)
{
	size_t	count;
	size_t	i;
	char	*result;
	char	c;

	if (n == 0)
		return (ft_strdup("0"));
	count = count_digits(n);
	result = (char *)malloc(sizeof(*result) * (count + 1));
	if (result)
	{
		if (n < 0)
			result[0] = '-';
		i = 1;
		while (n != 0)
		{
			c = '0' + (char)digit_abs(n % 10);
			result[(count) - i] = c;
			n = n / 10;
			i += 1;
		}
		result[count] = '\0';
	}
	return (result);
}
