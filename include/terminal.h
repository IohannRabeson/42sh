/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:18:30 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 20:57:24 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include <ft_types_def.h>

typedef struct termios	t_termios;

void	terminal_init(void);
void	terminal_destroy(void);
int		terminal_out_fd(void);
int		terminal_putchar(int c);
void	terminal_putstr(char const *str);
void	terminal_exec(char *cmd);
void	terminal_goto(t_ui x, t_ui y);
t_ui	terminal_width(void);
t_ui	terminal_height(void);

#endif
