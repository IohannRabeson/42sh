/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:56:47 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 19:12:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTO_H
# define HISTO_H
# include <ft_list.h>

struct			s_textedit;

typedef struct	s_histo
{
	t_list		str_list;
	t_list_node	*current;
	char		*old;
}				t_histo;

void	histo_init(t_histo *histo);
void	histo_destroy(t_histo *histo);
void	histo_push(t_histo *histo, char const *str);
void	histo_show_prev(t_histo *histo, struct s_textedit *te);
void	histo_show_next(t_histo *histo, struct s_textedit *te);

#endif
