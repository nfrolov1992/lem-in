/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellam_ford.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/14 16:25:09 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			bellamna_ford(t_data_room *rooms, t_data_link *links)
{
	t_data_link		*links_tmp;
	int				change;

	links_tmp = links;
	change = 0;
	while (links->next != NULL)
	{
		if (links->act == 1)
		{
			if (links->weight + links->from_room->length < \
					links->to_room->length)
			{
				links->to_room->length = links->weight + \
					links->from_room->length;
				links->to_room->from_link = links->from;
				change = 1;
			}
			if (change == 1)
			{
				links = links_tmp;
				change = 0;
			}
		}
		links = links->next;
	}
}
