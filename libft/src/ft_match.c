/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 19:33:58 by irabeson          #+#    #+#             */
/*   Updated: 2013/12/13 05:22:04 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_match(char const *str, char const *pattern)
{
	char	*temp;

	while (*str != '\0' && *pattern != '\0')
	{
		if (*pattern == '*')
		{
			++pattern;
			if (*pattern == '\0')
				return (1);
			temp = ft_strchr(str, *pattern);
			if (temp == NULL)
				return (0);
			else
				str = temp;
		}
		else if (*str == *pattern)
		{
			++str;
			++pattern;
		}
		else
			return (0);
	}
	return (*str == '\0' && *pattern == '\0');
}
