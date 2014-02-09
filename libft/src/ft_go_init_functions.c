/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_init_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 02:48:57 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:47:41 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt_flag.h"
#include "ft_memory.h"
#include "ft_string.h"

void	go_init_dash_flag(t_go_flag *flag, char const *arg, t_ui i)
{
	flag->key = ft_strdup(arg);
	flag->value = NULL;
	(void)i;
}

void	go_init_ddash_flag(t_go_flag *flag, char const *arg, t_ui i)
{
	flag->key = ft_strdup(arg);
	flag->value = NULL;
	(void)i;
}

void	go_init_dash_value_flag(t_go_flag *flag, char const *arg, t_ui i)
{
	char	*equal_pos;

	equal_pos = ft_strchr(arg, '=');
	flag->key = ft_strndup(arg, equal_pos - arg);
	flag->value = ft_strdup(equal_pos + 1);
	(void)i;
}

void	go_init_ddash_value_flag(t_go_flag *flag, char const *arg, t_ui i)
{
	char	*equal_pos;

	equal_pos = ft_strchr(arg, '=');
	flag->key = ft_strndup(arg, equal_pos - arg);
	flag->value = ft_strdup(equal_pos + 1);
	(void)i;
}
