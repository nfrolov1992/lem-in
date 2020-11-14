/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:12:09 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/14 16:35:43 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways				*way_set_end(t_ways *ways, t_way_param *param)
{
	param->begin = 1;
	param->baza = param->rooms->from_link;
	ways->name_room_way = param->rooms->name;
	ways->end = 1;
	ways->way = new_wayslist();
	ways->way->way_prev = ways;
	ways = ways->way;
	ways->name_room_way = param->baza;
	ways->way = new_wayslist();
	ways = ways->way;
	param->rooms = param->room_tm;
	param->ways_tm->length_way = param->ways_tm->length_way + 2;
	return (ways);
}

t_ways				*way_set_step(t_ways *ways, t_way_param *param)
{
	if (param->rooms->start == 1)
	{
		ways->start = 1;
		return (NULL);
	}
	param->baza = param->rooms->from_link;
	ways->name_room_way = param->baza;
	ways->way = new_wayslist();
	ways = ways->way;
	param->rooms = param->room_tm;
	param->ways_tm->length_way++;
	return (ways);
}

static t_way_param	init_peram(t_data_room *rooms)
{
	t_way_param param;

	param.begin = 0;
	param.baza = NULL;
	param.rooms = rooms;
	param.room_tm = rooms;
	return (param);
}

t_ways				*save_way(t_data_room *rooms)
{
	t_way_param		param;
	t_ways			*ways;

	param = init_peram(rooms);
	ways = new_wayslist();
	param.ways_tm = ways;
	while (TRUE)
	{
		if (param.begin == 0 && param.rooms->end == 1)
			ways = way_set_end(ways, &param);
		else if (param.baza != NULL && ft_strequ(param.baza, param.rooms->name))
		{
			if ((ways = way_set_step(ways, &param)) == NULL)
				break ;
		}
		else if (param.rooms->name == NULL)
		{
			clean_way(param.ways_tm);
			return (NULL);
		}
		else
			param.rooms = param.rooms->next;
	}
	return (param.ways_tm);
}
