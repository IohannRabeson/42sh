/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_absolute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:44:50 by irabeson          #+#    #+#             */
/*   Updated: 2014/01/24 17:06:35 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <ft_string.h>

char	*path_absolute(char const *pwd, char const *rel_path)
{
	t_list		parts;
	t_list_node	*it;
	char		**pwd_parts;
	char		*temp_str;
	t_ui		pwd_pos;

	list_init(&parts);
	ft_strsplit_list(rel, '/', &parts);
	ft_strsplit_array(pwd, '/', &pwd_parts);
	it = list_first(&parts);
	while (it)
	{
		temp_str = (char *)it->item;
		if (temp_str == NULL || ft_strlen(temp_str) == 0
				|| ft_strequ(temp_str, "."))
			continue ;
		if (ft_strequ(temp_str, ".."))
		{
			
		}
		it = it->next;
	}
	list_destroy(&parts);
	list_destroy(&pwd_parts);
}
