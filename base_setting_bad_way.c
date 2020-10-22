#include "lem_in.h"

t_data	*base_setting_bad_way(t_data_room *rooms, t_data_link *links, t_ways *ways)
{
	t_data_room		*rooms_tm;
	t_data_link		*links_tm;
	t_ways			*ways_tm;
	t_data			*data_lim;
	int				check;

	rooms_tm = rooms;
	links_tm = links;
	ways_tm = ways;

	data_lim = new_datalist();

	check = 0;

	while (links->next != NULL)
	{
		//выключаем поворот на не используемый путь
		if ((ft_strcmp(ways->name_room_way, links->from) == 0 && ft_strcmp(ways->way->name_room_way, links->to) == 0) ||
			(ft_strcmp(ways->name_room_way, links->to) == 0 && ft_strcmp(ways->way->name_room_way, links->from) == 0))
		{
			links->act = 0;
		}
		//все остальное, кроме начала
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
	data_lim->rooms = rooms_tm;
	data_lim->links = links_tm;
	// !!!!!НАДО ОТЧИСТЬТЬ ПУТЬ КОТОРЫЙ НЕ НУЖЕН ПАМЯТЬ
	//тестовый вариант проверки алгоритма поиска 2-ого пути
	//bellamna_ford(rooms_tm, links_tm);
	return (data_lim);
}