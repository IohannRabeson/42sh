/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_size_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 23:01:46 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 23:03:13 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>

size_t				ft_min_size_t(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t				ft_max_size_t(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
