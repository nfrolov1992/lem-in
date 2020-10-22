#include "lem_in.h"

// - проверям на использование в двух путях одной комнаты
// - проверка на разнонаправленные ребра двух комнат (необходимо исключить)
// 	при отсутствии общей комнаты в путях не учитывая комнаты с разнонаправленными 
// 	ребрами.
// - не использовать пути вдва раза длиннее суммы найденных путей до

t_ways	*save_new_way(t_data_room *rooms, t_data_ways *data_ways_tm, t_data_ways *data_ways)
{
	t_ways			*ways;
	t_ways			*ways_tm;
	t_data_room		*room_tm;
	t_ways			*data_ways_tm_tm;
	int				begin;
	char			*baza;

	begin = 0;
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
			ways->end = 1;
			ways->name_room_way = rooms->name;
			ways->way = new_wayslist();
			ways->way->way_prev = ways;
			ways = ways->way;
			ways->name_room_way = baza;
			ways->way = new_wayslist();
			ways = ways->way;
			rooms = room_tm;
			if (baza == NULL)
				return (NULL);
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
			//создаем ссылку на предыдущее значение
			ways->way_prev = new_wayslist();
			ways->way_prev->name_room_way = rooms->name;
			ways->way = new_wayslist();
			ways = ways->way;
			rooms = room_tm;
		}
		else
			rooms = rooms->next;
	}
	// data_ways->bad_way = 1;
	// data_ways->mod = 1;

	ways = ways_tm; //копия найденного пути
	while (data_ways_tm->next_way != NULL) // идем по путям которые есть
	{
		data_ways_tm_tm = data_ways_tm->way;
		while (data_ways_tm->way->way->name_room_way != NULL) // идем по комнатам в пути
		{
			while (ways_tm->way->name_room_way != NULL) // идем по комнатам в сравневаемом пути
			{
				if (ft_strcmp(data_ways_tm->way->name_room_way, ways_tm->way->name_room_way) == 0 &&
					ft_strcmp(data_ways_tm->way->way->name_room_way, ways_tm->name_room_way) == 0)
				{
					data_ways->mod += 2;
				}
				if (data_ways->mod != 0 && ft_strcmp(ways_tm->name_room_way, data_ways_tm->way->name_room_way) == 0 &&
					ft_strcmp(ways_tm->way_prev->name_room_way, data_ways_tm->way->way->name_room_way) == 0)
				{
					data_ways->mod -= 0;
				}
				else if (data_ways->mod != 0 && ft_strcmp(ways_tm->name_room_way, data_ways_tm->way->name_room_way) == 0 &&
					ft_strcmp(ways_tm->way->name_room_way, data_ways_tm->way->way_prev->name_room_way) == 0)
				{
					data_ways->mod -= 0;
				}
				else if (ft_strcmp(ways_tm->name_room_way, data_ways_tm->way->name_room_way) == 0 &&
					ways_tm->end != 1)
				{
					data_ways->bad_way += 1;
					// блокировать найденное ребро только одно (далее надо запустить белмана форда еще раз)
					// выходить из функции return() data_ways = NULL
					data_ways_tm->way = data_ways_tm_tm;
					return (ways_tm);
				}
				ways_tm = ways_tm->way;
			}
			ways_tm = ways; // обнавляем проверяемый путь
			data_ways_tm->way = data_ways_tm->way->way;
		}
		data_ways_tm->way = data_ways_tm_tm;
		data_ways_tm = data_ways_tm->next_way;
	}
	// if (data_ways->bad_way == 0 && data_ways->mod > 0)
	// 	{// пересечений нет, есть модификация пути
	// 		ft_printf("hello world");
	// 	}
	return (ways_tm);
}