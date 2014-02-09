/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:57:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:58:31 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_min_uint(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

unsigned int		ft_max_uint(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
