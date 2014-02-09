/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_flag_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 03:05:34 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:40:07 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt_flag.h"
#include <stdlib.h>

void	go_flag_destroy(t_go_flag *flag)
{
	if (flag)
	{
		if (flag->key)
		{
			free(flag->key);
			flag->key = NULL;
		}
		if (flag->value)
		{
			free(flag->value);
			flag->value = NULL;
		}
	}
}
