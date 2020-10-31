#include "lem_in.h"

t_ways	*save_way(t_data_room *rooms)
{
	t_ways			*ways;
	t_ways			*ways_tm;
	t_data_room		*room_tm;
	int				begin;
	char			*baza;
	int				length;

	begin = 0;
	length = 0;
	ways = new_wayslist();
	ways_tm = ways;
	room_tm = rooms;
	baza = NULL;
	while (TRUE)
	{
		if (begin == 0 && rooms->end == 1)
		{
			begin = 1;
			baza = rooms->from_link;
			ways->name_room_way = rooms->name;
			ways->end = 1;
			ways->way = new_wayslist();
			ways->way->way_prev = ways;
			ways = ways->way;
			ways->name_room_way = baza;
			ways->way = new_wayslist();
			ways = ways->way;
			rooms = room_tm;
			length = length + 2;
		}
		else if (baza != NULL && ft_strcmp(baza, rooms->name) == 0)
		{
			
			if (ft_strcmp(baza, rooms->name) == 0 && rooms->start == 1)
			{
				ways->start = 1;
				break;
			}
			baza = rooms->from_link;
			ways->name_room_way = baza;
			ways->way_prev = new_wayslist();
			ways->way_prev->name_room_way = rooms->name;
			ways->way = new_wayslist();
			ways = ways->way;
			rooms = room_tm;
			length++;
		}
		else if (rooms->name == NULL)
			return (NULL);
		else
			rooms = rooms->next;
	}
	ways_tm->length_way = length;
	return (ways_tm);
}