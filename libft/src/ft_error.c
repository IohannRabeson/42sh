/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:45:31 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/09 00:32:20 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_print.h"
#include <unistd.h>
#include <stdlib.h>

static char const	*g_err_messages[] =
{
	"success",
	"not enough memory",
	"no such file or directory",
	"is a directory",
	"not a directory",
	"operation not permitted",
	NULL
};

static char const	*get_error_desc(t_error_code code)
{
	if (code >= ERRC_COUNT)
		return ("unknow error");
	else
		return (g_err_messages[code]);
}

void	exit_errorm(char const *app,
					char const *message,
					int exit_code,
					t_exit_cb callback)
{
	ft_putstr_fd(app, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	else
		ft_putendl_fd("unspecified error", STDERR_FILENO);
	if (callback)
		callback();
	exit(exit_code);
}

void	exit_errorc(char const *app,
					t_error_code code,
					int exit_code,
					t_exit_cb callback)
{
	char const *message;

	message = get_error_desc(code);
	exit_errorm(app, message, exit_code, callback);
}
