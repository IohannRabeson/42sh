/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 00:51:47 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/29 18:18:13 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include "ft_types_def.h"
# include <string.h>

struct		s_list;

size_t		ft_strlen(char const *str);
char		*ft_strdup(char const *str);
char		*ft_strndup(char const *str, size_t n);
char		*ft_strcpy(char *dest, char const *source);
char		*ft_strncpy(char *dest, char const *source, size_t n);
char		*ft_strcat(char *dest, char const *source);
char		*ft_strncat(char *dest, char const *source, size_t n);
size_t		ft_strlcat(char *dest, char const *source, size_t size);
char		*ft_strchr(char const *str, int c);
char		*ft_strnchr(char const *str, int c, size_t n);
char		*ft_strrchr(char const *str, int c);
char		*ft_strstr(char *source, char const *search);
char		*ft_strnstr(char *source, char const *search, size_t n);
char		*ft_strapp(char const *left, char const *right);
char		*ft_strnapp(char const *origin, char const *str, size_t n);
int			ft_strcmp(char const *left, char const *right);
int			ft_strlcmp(char const *left, char const *right);
int			ft_strncmp(char const *left, char const *right, size_t n);
int			ft_strlncmp(const char *left, const char *right, size_t n);
char		*ft_strccpy_it(char *it, char c);
char		*ft_strcpy_it(char *it, char const *str);
int			ft_atoi(char const *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *str);
void		ft_striter(char *str, void (*f)(char *));
void		ft_striteri(char *str, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *str, char (*f)(char));
char		*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int			ft_strequ(char const *str1, char const *str2);
int			ft_strnequ(char const *str1, char const *str2, size_t n);
char		*ft_strsub(char const *str, unsigned int start, size_t len);
char		*ft_strjoin(char const *str1, char const *str2);
char		*ft_strtrim(char const *str);
char		**ft_strsplit(char const *str, char c);
char		**ft_strsplits(char const *str, char const *seps);
t_ui		ft_strsplit_list(char const *str, char c, struct s_list *results);
t_bool		ft_strfind(char const *str, char const *find,
					   t_ui *begin, t_ui *size);
t_bool		ft_strrep(char **origin,
					  char const *replace,
					  char const *replacement);
char		*ft_strnrep(char const *origin, t_ui begin, t_ui size,
						char const *replacement);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int n);
char		*ft_ltoa(long n);
char		*ft_ultoa(unsigned long n);
char		*ft_lltoa(long long n);
char		*ft_ulltoa(unsigned long long n);
int			ft_match(char const *str, char const *pattern);

#endif
