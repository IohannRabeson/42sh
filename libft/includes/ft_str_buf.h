/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_buf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:47:25 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 02:36:45 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_BUF_H
# define FT_STR_BUF_H
# include "ft_types_def.h"

typedef struct	s_str_buf
{
	t_ui	size;
	t_ui	capacity;
	char	*buffer;
}				t_str_buf;

void			str_buf_init(t_str_buf *strbuf);
void			str_buf_destroy(t_str_buf *strbuf);
void			str_buf_clone(t_str_buf *clone, t_str_buf const *strbuf);
void			str_buf_reserve(t_str_buf *strbuf, t_ui new_cap);
void			str_buf_clear(t_str_buf *strbuf);
char			*str_buf_get(t_str_buf const *strbuf);
char			*str_buf_getsub(t_str_buf const *strbuf, t_ui start,
								t_ui length);
char			str_buf_get_char(t_str_buf const *strbuf, t_ui pos);
char			str_buf_get_last_char(t_str_buf const *strbuf);
t_ui			str_buf_size(t_str_buf const *strbuf);
void			str_buf_assign(t_str_buf *strbuf, char const *str);
void			str_buf_app_char(t_str_buf *strbuf, char c);
void			str_buf_app_str(t_str_buf *strbuf, char const *str);
void			str_buf_app_strn(t_str_buf *strbuf, char const *str, t_ui n);
void			str_buf_insert_char(t_str_buf *strbuf, t_ui pos, char c);
void			str_buf_insert_str(t_str_buf *strbuf, t_ui pos,
									char const *str);
void			str_buf_insert_strn(t_str_buf *strbuf, t_ui pos,
									char const *str, t_ui n);
t_ui			str_buf_erase(t_str_buf *strbuf, t_ui start, t_ui length);
void			str_buf_pop_front(t_str_buf *strbuf);
void			str_buf_pop_back(t_str_buf *strbuf);
t_ui			str_buf_write(t_str_buf const *strbuf, int fd);
t_ui			str_buf_read(t_str_buf *str, int fd);
t_bool			str_buf_find_first_char(t_str_buf const *str, t_ui *pos);
t_bool			str_buf_find(t_str_buf *str_buf, char const *search,
								t_ui *start);
void			str_buf_replace_all(t_str_buf *str_buf,
									char const *rep_str,
									char const *new_str);

#endif
