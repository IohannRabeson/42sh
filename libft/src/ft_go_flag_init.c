/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_flag_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 02:31:34 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:57:30 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_getopt_flag.h"
#include "ft_string.h"

static int			double_dash(char const *arg, t_go_ftype *type)
{
	if (arg[0] == '-' && arg[1] == '-')
	{
		if (ft_strchr(arg, '=') != NULL)
			*type = GOFT_DOUBLE_DASH_VALUE;
		else
			*type = GOFT_DOUBLE_DASH;
		return (1);
	}
	return (0);
}

static int			simple_dash(char const *arg, t_go_ftype *type)
{
	if (arg[0] == '-' && arg[1] != '-' && arg[1] != '\0')
	{
		if (ft_strchr(arg, '=') != NULL)
			*type = GOFT_DASH_VALUE;
		else
			*type = GOFT_DASH;
		return (1);
	}
	return (0);
}

static t_go_ftype	get_arg_type(char const *arg)
{
	const t_ui	arg_len = ft_strlen(arg);
	t_go_ftype	type;

	if (arg_len == 0)
		return (GOFT_INVALID);
	if (!double_dash(arg, &type) && !simple_dash(arg, &type))
	{
		if (ft_strchr(arg, '=') != NULL)
			type = GOFT_KEY_VALUE;
		else
			type = GOFT_VALUE;
	}
	return (type);
}

t_go_ftype			go_flag_init(t_go_flag *flag, char const *arg, t_ui i)
{
	static t_go_init_flag_func init_funcs[GOFT_COUNT] =
	{
		&go_init_dash_flag,
		&go_init_ddash_flag,
		&go_init_dash_value_flag,
		&go_init_ddash_value_flag,
		&go_init_key_value_flag,
		&go_init_value_flag
	};

	flag->type = get_arg_type(arg);
	init_funcs[flag->type](flag, arg, i);
	return (flag->type);
}
