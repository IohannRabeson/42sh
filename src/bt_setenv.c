/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:23:49 by irabeson          #+#    #+#             */
/*   Updated: 2014/04/30 02:29:04 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <ft_strarr.h>

int			bt_setenv(t_shell *shell, t_cmd_params const *params)
{
	char	*key;
	char	*value;

	if (strarr_size(params->args) >= 2)
	{
		key = params->args[1];
		value = params->args[2];
		if (value)
			env_replace(&shell->env, key, value);
		else
			env_replace(&shell->env, key, "");
		return (1);
	}
	else
		return (bt_env(shell, params));
}
