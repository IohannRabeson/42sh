/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 00:48:59 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 16:07:31 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include <string.h>

void		ft_putchar(char c);
void		ft_putstr(char const *str);
void		ft_putstrn(char const *str, size_t n);
void		ft_putendl(char const *str);
void		ft_putnbr(int n);
void		ft_putull(unsigned long long n);
void		ft_putul(unsigned long n);
void		ft_putui(unsigned int n);
void		ft_putll(long long n);
void		ft_putl(long n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *str, int fd);
void		ft_putstrn_fd(char const *str, size_t n, int fd);
void		ft_putendl_fd(char const *str, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putull_fd(unsigned long long n, int fd);
void		ft_putul_fd(unsigned long n, int fd);
void		ft_putui_fd(unsigned int n, int fd);
void		ft_putll_fd(long long n, int fd);
void		ft_putl_fd(long n, int fd);

#endif
