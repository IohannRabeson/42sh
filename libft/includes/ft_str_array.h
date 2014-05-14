/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 05:39:04 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:50:28 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_ARRAY_H
# define FT_STR_ARRAY_H

# include "ft_types_def.h"
# include "ft_functional.h"

struct s_list;

char	**str_array_malloc(t_ui size);
char	**str_array_realloc(char **array, t_ui new_size);
char	**str_array_from_array(int count, char **strs);
char	**str_array_from_list(struct s_list const *str_list);
void	str_array_free(char **array);
char	**str_array_append(char **array, char const *str);
void	str_array_foreach(char **array, t_apl_func afunc);
void	str_array_sort(char **array, t_cmp_func cmp_func);
t_ui	str_array_size(char **array);
t_bool	str_array_find(char **array, char const *str, t_ui *index);

#endif
