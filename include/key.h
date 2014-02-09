/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:47:44 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 18:17:02 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H
# include <ft_types_def.h>

# define	KEYCODE_SIZE	4

typedef char	t_key[KEYCODE_SIZE];

void	key_bzero(t_key key);
t_bool	key_read(t_key key, int fd);
void	key_from_chars(t_key key, char c0, char c1, char c2, char c3);
void	key_from_str(t_key key, char const *str);
void	key_from_termcap(t_key key, char c0, char c1, char const *keycode);
void	key_put(t_key const key);
int		key_cmp(t_key const key_a, t_key const key_b);
t_bool	key_is_char(t_key const key);
char	key_get_char(t_key const key);

#endif
