/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:41:42 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/12 20:18:32 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		reset_length(t_data_link *links)
{
	if (links->from_room->start == 1)
	{
		links->from_room->length = 0;
		links->from_room->from_link = NULL;
	}
	else
	{
		links->from_room->length = 2000000000;
		links->from_room->from_link = NULL;
	}
	if (links->to_room->start == 1)
	{
		links->to_room->length = 0;
		links->to_room->from_link = NULL;
	}
	else
	{
		links->to_room->length = 2000000000;
		links->to_room->from_link = NULL;
	}
}

void			base_setting(t_data *data_lim, t_ways *ways)
{
	t_data_link		*links;
	t_ways			*ways_tm;

	links = data_lim->links;
	ways_tm = ways;
	while (links->next != NULL)
	{
		while (ways->way->name_room_way != NULL)
		{
			if (ways->end == 0 && ways->start == 0 && \
			((ft_strequ(ways->name_room_way, links->to)) || \
			(ft_strequ(ways->name_room_way, links->from))))
				links->act = 0;
			ways = ways->way;
		}
		ways = ways_tm;
		reset_length(links);
		links = links->next;
	}
	return ;
}
