/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 04:20:12 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:10:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_print.h>

void	ft_putstr(char const *str)
{
	ft_putstr_fd(str, 1);
}
