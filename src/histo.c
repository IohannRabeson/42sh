/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:59:58 by irabeson          #+#    #+#             */
/*   Updated: 2014/05/25 05:37:11 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "histo.h"
#include "textedit.h"
#include "path.h"
#include "app.h"
#include <ft_memory.h>
#include <ft_string.h>
#include <ft_list.h>
#include <stdio.h>

void	histo_init(t_histo *histo)
{
	ft_bzero(histo, sizeof(*histo));
	list_init(&histo->str_list, free);
	str_buf_init(&histo->temp_cmdline);
	histo_load_config(&app_instance()->histo, ".42sh_history");
}

void	histo_destroy(t_histo *histo)
{
	histo_save_config(&app_instance()->histo, ".42sh_history");
	list_destroy(&histo->str_list);
	str_buf_destroy(&histo->temp_cmdline);
	ft_bzero(histo, sizeof(*histo));
}

t_ui	histo_size(t_histo const *histo)
{
	return list_count(&histo->str_list);
}
