/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 22:54:09 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:33:22 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H
# include <string.h>

typedef enum	e_align
{
	AL_LEFT,
	AL_CENTER,
	AL_RIGHT
}				t_align;

char	*ft_format_align(char const *source, size_t size, t_align align);
char	*ft_format_csuffix(char *str, char suffix);

#endif
