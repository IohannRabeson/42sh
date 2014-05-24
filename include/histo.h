/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:56:47 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 00:22:48 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTO_H
# define HISTO_H
# include <ft_list.h>
# include <ft_str_buf.h>

struct s_textedit;

typedef struct	s_histo
{
	t_list		str_list;
	t_list_node	*current;
	t_str_buf	temp_cmdline;
	int			end;
}				t_histo;

typedef void(*t_histo_entry_func)(t_ui i, char *str);
typedef void(*t_histo_entry_cfunc)(t_ui i, char const *str);

void			histo_init(t_histo *histo);
void			histo_destroy(t_histo *histo);
t_ui			histo_size(t_histo const *histo);
void			histo_show_prev(t_histo *histo, struct s_textedit *te);
void			histo_show_next(t_histo *histo, struct s_textedit *te);
void			histo_foreach(t_histo *histo, t_histo_entry_func func);
void			histo_cforeach(t_histo const *histo, t_histo_entry_cfunc func);
void			histo_push(t_histo *histo, char const *str);
void			histo_pop_last(t_histo *histo);
void			histo_clear(t_histo *histo);
void			histo_remove(t_histo *histo, t_ui i);

#endif
