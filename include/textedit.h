/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textedit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 22:03:38 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 19:08:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTEDIT_H
# define TEXTEDIT_H
# include <ft_str_buf.h>

typedef			void(*t_val_func)(char const *);

typedef struct	s_cursor
{
	t_ui	buffer_pos;
	t_ui	col;
	t_ui	row;
}				t_cursor;

typedef struct	s_prompt
{
	char	*str;
	t_ui	size;
}				t_prompt;

typedef struct	s_textedit
{
	t_str_buf	buffer;
	t_cursor	cursor;
	t_prompt	prompt;
	t_ui		width;
	t_ui		height;
	t_ui		scroll;
	t_bool		modified;
	t_bool		first;
	t_val_func	val_func;
}				t_textedit;

void	textedit_init(t_textedit *te, char const *prompt, t_val_func val_func);
void	textedit_destroy(t_textedit *te);
void	textedit_reset(t_textedit *te);
void	textedit_display(t_textedit *te);
t_bool	textedit_can_goto(t_textedit const *te, t_ui buf_pos);
void	textedit_validate(t_textedit *te);
t_bool	textedit_multiline(t_textedit const *textedit);
void	textedit_replace_text(t_textedit *textedit, char const *str);
char	*textedit_get_text(t_textedit const *te);
void	cursor_next_char(t_textedit *textedit);
void	cursor_prev_char(t_textedit *textedit);
void	cursor_next_word(t_textedit *te);
void	cursor_prev_word(t_textedit *te);
void	cursor_advance(t_textedit *te, t_ui n);
void	cursor_back(t_textedit *te, t_ui n);
void	cursor_insert(t_textedit *te, char c);
void	cursor_insert_str(t_textedit *te, char const *str);
void	cursor_backspace(t_textedit *te);
void	cursor_suppr(t_textedit *te);

#endif
