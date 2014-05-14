/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems_preprocess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:56:11 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/14 05:55:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "lexem.h"
#include "app.h"
#include "env.h"
#include <ft_list.h>
#include <ft_str_buf.h>
#include <ft_string.h>
#include <stdlib.h>

static t_bool		lexem_is_spaces(t_lexem *lex)
{
	return (lexem_type_is(lex, ST_SKIP_SPACES));
}

static t_bool		lexem_is_delim(t_lexem *lex)
{
	return (lexem_type_is(lex, ST_DELIM_PARAM_OUT)
			|| lexem_type_is(lex, ST_DELIM_PARAM_IN));
}

static t_bool		lexem_is_constant(t_lexem const *lex)
{
	if (lex == NULL && lex->state_id != ST_PARAM)
		return (false);
	return (lex->str && lex->str[0] == '$' && ft_strlen(lex->str) > 1);
}

void				replace_constants(t_str_buf *buffer, t_env const *env)
{
	char			*key;
	t_env_var const	*value;

	key = ft_strndup(buffer->buffer + 1, buffer->size - 1);
	value = env_cfind(env, key);
	if (value)
	{
		str_buf_clear(buffer);
		str_buf_app_str(buffer, value->value);
	}
	if (key)
		free(key);
}

static void			preprocess_lexem(t_lexem *lexem)
{
	t_app const * const	app = app_instance();
	t_str_buf			buffer;
	char const			*home_path;

	if (lexem->str)
	{
		home_path = env_get_value(&app->env, "HOME");
		str_buf_init(&buffer);
		str_buf_app_strn(&buffer, lexem->str, lexem->size);
		if (lexem_is_constant(lexem))
			replace_constants(&buffer, &app->env);
		if (home_path && lexem->state_id == ST_PARAM)
			str_buf_replace_all(&buffer, "~", home_path);
		free(lexem->str);
		lexem->str = str_buf_get(&buffer);
		str_buf_destroy(&buffer);
	}
}

void				lexems_preprocess(t_list *lexems)
{
	list_foreach(lexems, preprocess_lexem);
	list_erase_if(lexems, lexem_is_spaces);
	list_erase_if(lexems, lexem_is_delim);
}
