/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 05:54:15 by irabeson          #+#    #+#             */
/*   Updated: 2013/12/13 13:18:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

inline static size_t		count_digits(unsigned long long n)
{
	size_t	result;

	result = 1;
	while (n >= 10)
	{
		result += 1;
		n = n / 10;
	}
	return (result);
}

char						*ft_ulltoa(unsigned long long n)
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
		i = 1;
		while (n != 0)
		{
			c = '0' + (char)(n % 10);
			result[(count) - i] = c;
			n = n / 10;
			i += 1;
		}
		result[count] = '\0';
	}
	return (result);
}
