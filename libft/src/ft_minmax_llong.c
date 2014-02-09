/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_llong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:54:42 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:55:45 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long					ft_min_llong(long long a, long long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

long long					ft_max_llong(long long a, long long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
