#include "lem_in.h"

void	base_setting(t_data_room *rooms, t_data_link *links, t_ways *ways)
{
	t_ways			*ways_tm;

	ways_tm = ways;
	while (links->next != NULL)
	{
		while (ways->way->name_room_way != NULL)
		{
			if (ways->end == 0 && ways->start == 0 && ((ft_strcmp(ways->name_room_way, links->to)) == 0 || (ft_strcmp(ways->name_room_way, links->from) == 0)))
				links->act = 0;
			ways = ways->way;
		}
		ways = ways_tm;
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
		links = links->next;
	}
	return ;
}