#include "lem_in.h"

//выполняю поиск пути
void			bellamna_ford(t_data_room *rooms, t_data_link *links)
{
	t_data_room *room_tmp;
	t_data_link *links_tmp;
	int			change;

	room_tmp = rooms;
	links_tmp = links;
	change = 0;

	while (links->next != NULL)
	{
		if (links->act == 1)
		{
			if (links->weight + links->from_room->length < links->to_room->length)
			{
				links->to_room->length = links->weight + links->from_room->length;
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
