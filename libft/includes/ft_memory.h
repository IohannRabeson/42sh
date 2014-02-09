/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 00:47:53 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/22 04:24:13 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H
# include <string.h>

void	ft_bzero(void *s, size_t n);
void	*ft_realloc(void *ptr, size_t size_of, size_t new_size);
void	*ft_memset(void *ptr, int value, size_t len);
void	*ft_memcpy(void *dest, const void *str, size_t n);
void	*ft_memccpy(void *dest, void const *str, char c, size_t n);
void	*ft_memmove(void *dest, void const *str, size_t n);
void	*ft_memchr(void const *str, int c, size_t n);
int		ft_memcmp(void const *ptr1, void const *ptr2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);

#endif
