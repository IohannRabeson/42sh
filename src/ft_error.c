/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:45:31 by irabeson          #+#    #+#             */
/*   Updated: 2014/02/04 03:17:50 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

static char const	*g_err_messages[] =
{
	"success",
	"command not found.",
	"no such file or directory",
	"is a directory",
	"not a directory",
	"operation not permitted",
	"invalid argument",
	"too few arguments",
	NULL
};

static char const	*get_error_desc(t_error_code code)
{
	if (code >= ERRC_COUNT)
		return ("unknow error");
	else
		return (g_err_messages[code]);
}

void				exit_errorm(char const *message)
{
	ft_putstr_fd("ft_sh: ", STDERR_FILENO);
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	else
		ft_putendl_fd("unspecified error", STDERR_FILENO);
	exit(1);
}

void				exit_errorc(t_error_code code)
{
	char const *	message;

	message = get_error_desc(code);
	ft_putstr_fd("ft_sh: ", STDERR_FILENO);
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	else
		ft_putendl_fd("unknown error", STDERR_FILENO);
	exit(1);
}
