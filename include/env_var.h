/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:45:56 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 18:43:25 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_H
# define ENV_VAR_H

# include <ft_types_def.h>

typedef struct	s_env_var
{
	char	*key;
	char	*value;
}				t_env_var;

t_bool			env_var_init(t_env_var *env_var, char const *str);
t_bool			env_var_init_kv(t_env_var *env_var, char const *key,
								char const *value);
void			env_var_destroy(t_env_var *env_var);
void			env_var_set_value(t_env_var *env_var, char const *str);

#endif
