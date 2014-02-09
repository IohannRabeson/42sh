/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_ullong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:56:03 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:56:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_min_ullong(unsigned long long a, unsigned long long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

unsigned long long	ft_max_ullong(unsigned long long a, unsigned long long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
