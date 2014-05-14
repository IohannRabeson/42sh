/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:42:00 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 21:46:56 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

typedef void(t_exit_cb)(void);

typedef enum	e_error_code
{
	ERRC_SUCCESS = 0,
	ERRC_NOT_ENOUGH_MEMORY,
	ERRC_NO_SUCH_FILE,
	ERRC_IS_DIR,
	ERRC_IS_NOT_DIR,
	ERRC_NO_PERMISSIONS,
	ERRC_COUNT
}				t_error_code;

void	exit_errorm(char const *app,
					char const *message,
					int exit_code,
					t_exit_cb callback);

void	exit_errorc(char const *app,
					t_error_code code,
					int exit_code,
					t_exit_cb callback);

#endif
