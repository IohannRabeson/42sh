/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 01:51:12 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:40:09 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H
# include "ft_btree.h"
# include "ft_types_def.h"

typedef struct	s_getopt
{
	t_btree	flags;
}				t_getopt;

void				getopt_init_args(t_getopt *getopt, int argc, char **argv);
void				getopt_init(t_getopt *getopt);
void				getopt_destroy(t_getopt *getopt);
int					getopt_contains(t_getopt const *getopt, char const *flag);
int					getopt_hasvalue(t_getopt const *getopt, char const *flag);
char				*getopt_value(t_getopt const *getopt, char const *flag);
struct s_go_flag	*getopt_parse(t_getopt *getopt, char const *str, t_ui i);

#endif
