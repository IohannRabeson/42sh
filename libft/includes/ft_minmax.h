/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 04:21:10 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 23:02:48 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINMAX_H
# define FT_MINMAX_H
# include <stddef.h>

int					ft_min_int(int a, int b);
long				ft_min_long(long a, long b);
long long			ft_min_llong(long long a, long long b);
unsigned int		ft_min_uint(unsigned int a, unsigned int b);
unsigned int long	ft_min_ulong(unsigned long a, unsigned long b);
unsigned long long	ft_min_ullong(unsigned long long a, unsigned long long b);
unsigned long long	ft_min_ullong(unsigned long long a, unsigned long long b);
size_t				ft_min_size_t(size_t a, size_t b);
int					ft_max_int(int a, int b);
long				ft_max_long(long a, long b);
long long			ft_max_llong(long long a, long long b);
unsigned int		ft_max_uint(unsigned int a, unsigned int b);
unsigned int long	ft_max_ulong(unsigned long a, unsigned long b);
unsigned long long	ft_max_ullong(unsigned long long a, unsigned long long b);
unsigned long long	ft_max_ullong(unsigned long long a, unsigned long long b);
size_t				ft_max_size_t(size_t a, size_t b);

#endif
