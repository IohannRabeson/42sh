/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_flag.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 02:40:44 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:40:08 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_FLAG_H
# define FT_GETOPT_FLAG_H
# include "ft_types_def.h"
# include <stddef.h>

typedef enum	e_go_ftype
{
	GOFT_INVALID = -1,
	GOFT_DASH = 0,
	GOFT_DOUBLE_DASH,
	GOFT_DASH_VALUE,
	GOFT_DOUBLE_DASH_VALUE,
	GOFT_KEY_VALUE,
	GOFT_VALUE,
	GOFT_COUNT
}				t_go_ftype;

typedef struct	s_go_flag
{
	t_go_ftype	type;
	char		*key;
	char		*value;
}				t_go_flag;

typedef 		void	(*t_go_init_flag_func)(t_go_flag *, char const *,
											   t_ui);

t_go_ftype	go_flag_init(t_go_flag *flag, char const *arg, t_ui i);
void		go_flag_destroy(t_go_flag *flag);
void		go_init_dash_flag(t_go_flag *flag, char const *arg, t_ui i);
void		go_init_ddash_flag(t_go_flag *flag, char const *arg, t_ui i);
void		go_init_dash_value_flag(t_go_flag *flag, char const *arg, t_ui i);
void		go_init_ddash_value_flag(t_go_flag *flag, char const *arg, t_ui i);
void		go_init_key_value_flag(t_go_flag *flag, char const *arg, t_ui i);
void		go_init_value_flag(t_go_flag *flag, char const *arg, t_ui i);

#endif
