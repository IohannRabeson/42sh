/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:53:58 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:54:35 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long					ft_min_long(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

long					ft_max_long(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
