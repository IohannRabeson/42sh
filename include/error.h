/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:42:00 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/21 20:40:50 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum	e_error_code
{
	ERRC_SUCCESS = 0,
	ERRC_COMMAND_NOT_FOUND,
	ERRC_NO_SUCH_FILE,
	ERRC_IS_DIR,
	ERRC_IS_NOT_DIR,
	ERRC_NO_PERMISSIONS,
	ERRC_INVALID_ARG,
	ERRC_TOO_FEW_ARGS,
	ERRC_NOT_ENOUGH_MEMORY,
	ERRC_COUNT
}				t_error_code;

void	exit_errorm(char const *message);
void	exit_errorc(t_error_code code);

#endif
