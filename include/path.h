/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 22:54:40 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 22:58:17 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

char	*path_absolute(char const *current_dir, char const *rel_path);
char	*path_follow_link(char const *lnk_path);
char	*path_concat(char const *base_path, char const *appended);
t_bool	path_is_relative(char const *path);
t_bool	path_is_lnk(char const *path);
t_bool	path_is_dir(char const *path);
t_bool	path_is_file(char const *path);
t_bool	path_exists(char const *path);
t_bool	path_is_relative(char const *path);
t_bool	path_is_absolute(char const *path);
t_bool	path_can_be_executed(char const *path);

#endif
