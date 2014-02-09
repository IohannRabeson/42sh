/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_csuffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 18:29:39 by irabeson          #+#    #+#             */
/*   Updated: 2013/12/15 18:45:32 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <stdlib.h>

char	*ft_format_csuffix(char *str, char suffix)
{
	size_t	len;
	char	*new;

	len = ft_strlen(str) + 1;
	new = (char *)malloc(sizeof(*new) * (len + 1));
	if (new)
	{
		if (str)
		{
			ft_strcpy(new, str);
			free(str);
		}
		new[len - 1] = suffix;
		new[len] = '\0';
	}
	return (new);
}
