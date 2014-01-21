/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 20:15:52 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 20:24:09 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H
# include "types_def.h"
# include "env.h"

typedef struct	s_app
{
	t_env	env;
	t_bool	run;
}				t_app;

t_app	*app_instance(void);
void	app_init(int argc, char **argv, char **environs);
void	app_destroy(void);
void	app_stop(void);
t_bool	app_run(void);

#endif
