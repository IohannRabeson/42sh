/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_ulong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:57:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:58:21 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long		ft_min_ulong(unsigned long a, unsigned long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

unsigned long		ft_max_ulong(unsigned long a, unsigned long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
