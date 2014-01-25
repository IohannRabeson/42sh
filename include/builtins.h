/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:22:03 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/25 16:32:50 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

struct			s_env;
struct			s_builtin;

typedef struct	s_builtins
{
	t_builtin	*buitins;
	t_ui		size;
	t_ui		capacity;
}				t_builtins;

#endif
