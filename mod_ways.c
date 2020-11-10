#include "lem_in.h"

// t_ways			*new_waylost(t_ways *way_lost)
// {
// 	t_ways *way_tmp;
// 	t_ways *way_tmp_tm;


// 	way_tmp = new_wayslist();
// 	way_tmp_tm = way_tmp;
// 	while(way_lost->way != NULL)
// 	{
// 		way_tmp->name_room_way = way_lost->name_room_way;
// 		way_tmp->way = new_wayslist();
// 		way_tmp = way_tmp->way;
// 		way_lost = way_lost->way;
// 	}
// 	return (way_tmp_tm);
// }

t_ways			*go_wtt(t_ways *way, t_data_ways *buffer_2)
{
	t_ways *way_tm;
	t_data_ways *buffer_2_tm;
	// t_ways *way_tm_tm = NULL;

	way_tm = way;
	buffer_2_tm = buffer_2;
	while (way->way != NULL)
	{
		while (buffer_2->next_way != NULL)
		{
			if (way->way->name_room_way != NULL && ft_strcmp(way->way->name_room_way, buffer_2->way->name_room_way) == 0) // если нашли что заменить
			{
				// if (way->way->way != NULL)
				// 	buffer_2->way->way_dop = way->way->way; // way_tm_tm = new_waylost(way->way->way);
				way->way->way_dop = buffer_2->way;
				buffer_2 = buffer_2_tm;
				break ;
				// return (way_tm);
			}
			buffer_2 = buffer_2->next_way;
		}
		buffer_2 = buffer_2_tm;
		way = way->way;
	}
	return (way_tm);
}

t_data_ways		*wtt_room(t_data_ways *data_ways, t_data_ways *buffer_2)
{
	t_data_ways *data_ways_tmp;

	data_ways_tmp = data_ways;
	while (data_ways->next_way != NULL)
	{
		data_ways->way = go_wtt(data_ways->way, buffer_2);
		data_ways = data_ways->next_way;
	}

	return(data_ways_tmp);
}

t_ways			*revers_way(t_ways *way)
{
	t_ways *way_tm;
	t_ways *way_tm_tm;

	way_tm = new_wayslist();
	way_tm_tm = way_tm;
	while (way->way != NULL)
	{
		if (way->way->way == NULL)
		{
			way->way = NULL;
			break;
		}
		way->way->way_prev = way;
		way = way->way;
	}
	while (way != NULL)
	{
		way_tm->name_room_way = way->name_room_way;
		way_tm->way = new_wayslist();
		way_tm = way_tm->way;
		way = way->way_prev;
	}
	return (way_tm_tm);
}

t_data_ways		*revers_data_way(t_data_ways *data_ways)
{
	t_data_ways *data_ways_tmp;

	data_ways_tmp = data_ways;
	while (data_ways->next_way)
	{
		data_ways->way = revers_way(data_ways->way);
		data_ways = data_ways->next_way;
	}
	return (data_ways_tmp);
}

int		check_way2(char *buffer_1, t_ways *ways_tmp)
{
	if (buffer_1 != NULL && ft_strstr(buffer_1, ways_tmp->name_room_way) == 0)
		return (1); // не неашли пересечение
	return (0); // если нашли пересечение
}

char			*check_way(char *buffer_1, t_data_ways *buffer_2, t_ways *ways_tmp, int *t)
{
	t_data_ways *buffer_2_tmp;
	
	buffer_2_tmp = buffer_2;
	ways_tmp = ways_tmp->way;

	while (ways_tmp->way->way != NULL) // идем по пути
	{
		if (check_way2(buffer_1, ways_tmp) == 0) // записать данные !!!!!!!!!!! с комнаты
		{
			while (buffer_2->way != NULL)
			{
				if (ft_strcmp(buffer_2->way->name_room_way, ways_tmp->name_room_way) == 0)
					ways_tmp->ch_way = 1;
				buffer_2 = buffer_2->next_way;
			}
			if (ways_tmp->ch_way != 1)
			{
				buffer_2->way = new_wayslist();
				buffer_2->way->name_room_way = ways_tmp->name_room_way;
				buffer_2->next_way = new_ways_datalist();
				buffer_2 = buffer_2->next_way;
			}
			*t = 1;
			ways_tmp->way = NULL;
			ways_tmp->way = new_wayslist();
			break ;
		}
		else 
		{
			buffer_1 = ft_strjoin(buffer_1, ways_tmp->name_room_way);
			buffer_1 = ft_strjoin(buffer_1, "L");
		}
	// 1 случай ищем пересекающиеся комнаты и не нашли, заполнили буффер 1	
	// 2 случай нашли пересекающуеся комнату, выделили память в буффер 2 и записали ДАННЫЕ
	// остаток пути в NULL
		ways_tmp = ways_tmp->way;
	}
	return (buffer_1);
}

t_data_ways		*mod_ways(t_data_ways *data_ways)
{
	t_ways	*ways_tmp;
	t_data_ways *data_ways_tmp;
	char *buffer_1; // буффер для уникальных комнат
	t_data_ways *buffer_2; // буффер для комнат пересечений
	int			t;

	t = 0;
	buffer_1 = ft_strnew(1);
	buffer_2 = new_ways_datalist();
	data_ways = revers_data_way(data_ways);
	data_ways_tmp = data_ways;
	while (data_ways->next_way != NULL) // иду по найденным путям
	{
		ways_tmp = data_ways->way;
		buffer_1 = check_way(buffer_1, buffer_2, ways_tmp, &t);
		if (t == 0)
			data_ways->go_way_e = 1;
		t = 0;
		data_ways = data_ways->next_way;
	}
	data_ways_tmp = wtt_room(data_ways_tmp, buffer_2);
	
	return (data_ways_tmp);
}