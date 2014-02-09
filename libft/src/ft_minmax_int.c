/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:52:39 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 22:53:44 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int					ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
