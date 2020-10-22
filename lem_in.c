#include "lem_in.h"

t_data	*base_setting_mod(t_data_room *rooms, t_data_link *links, t_data_ways *ways)
{
	t_data_room			*rooms_tm;
	t_data_link			*links_tm;
	t_data_ways			*ways_tm;
	t_data				*data_lim;
	t_ways				*ways_one;

	rooms_tm = rooms;
	links_tm = links;
	ways_tm = ways;

	data_lim = new_datalist();

	while (links->next != NULL)
	{
		ways_one = ways->way;
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
		while (ways != NULL)
		{
			if ((ways_one == NULL && ways->next_way != NULL) || ways_one->way->name_room_way == NULL)
			{
				ways = ways->next_way;
				if (ways == NULL)
					break;
				ways_one = ways->way;
			}
			else if (ways->mod == 0)
			{
				if (((ft_strcmp(ways_one->name_room_way, links->from) == 0 ) && ((ft_strcmp(ways_one->way->name_room_way, links->to)) == 0)) ||
					((ft_strcmp(ways_one->name_room_way, links->to) == 0) && ((ft_strcmp(ways_one->way->name_room_way, links->from)) == 0)))
					{
						links->act = 0;
						links->weight = 1;
						links = links->next;
						links->act = 0;
						links->weight = 1;
						links = links->next;
						break ;
					}
					ways_one = ways_one->way;
			}
			else
			{	
					if ((((ft_strcmp(ways_one->name_room_way, links->from) == 0 ) && ((ft_strcmp(ways_one->way->name_room_way, links->to)) == 0)) ||
						((ft_strcmp(ways_one->name_room_way, links->to) == 0) && ((ft_strcmp(ways_one->way->name_room_way, links->from)) == 0))) &&
						(ways_one->no_use == 1 && ways_one->way->no_use == 1))
					{// перекрестные ссылки
						links->act = 0;
						links->weight = 1;
						links = links->next;
						links->act = 0;
						links->weight = 1;
						links = links->next;
						break ;
					}

					if (((ft_strcmp(ways_one->name_room_way, links->from) == 0 ) && ((ft_strcmp(ways_one->way->name_room_way, links->to)) == 0)) ||
						((ft_strcmp(ways_one->name_room_way, links->to) == 0) && ((ft_strcmp(ways_one->way->name_room_way, links->from)) == 0)))
					{
						if (links->to_room->start == 1)
						{
							links->act = 0;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							links->act = 1;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							break ;
						}
						else if (links->from_room->start == 1)
						{
							links->act = 1;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							links->act = 0;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							break ;
						}
						if (links->from_room->end == 1)
						{
							links->act = 0;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							links->act = 1;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							break ;
						}
						else if (links->to_room->end == 1)
						{
							links->act = 1;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							links->act = 0;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							break ;
						}
						else
						{
							links->act = 1;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							links->act = 1;
							links->count_way = 0;
							links->weight = 1;
							links = links->next;
							break ;
						}
					}
					ways_one = ways_one->way;
			}
				
		}
		ways = ways_tm;
		

	}
	data_lim->links = links_tm;
	data_lim->rooms = rooms_tm;
	return (data_lim);
}

void	mod_way(t_ways *ways_mod, t_data_ways *ways_all)
{
	// 1. нахожу путь который надо модифицировать mod > 0
	// 2. записываю его во временную переменную
	// 3. записал исходные пути 
	// 4. начал поиск перекрестных путей т.е. второй путь 
	t_data_ways		*ways_tm_all; // общий путь копия
	t_ways			*ways_tm_mod; // путь который модифицирован
	t_ways			*ways_one;

	ways_tm_mod = ways_mod;
	ways_tm_all = ways_all;
	while (ways_all->mod == 0) // иду по путям
	{
		ways_one = ways_all->way;
		while (ways_one->way->way != NULL)
		{
			while (ways_mod->way->way != NULL)
			{
				if ((ft_strcmp(ways_mod->name_room_way, ways_one->way->name_room_way) == 0) &&
					ft_strcmp(ways_one->name_room_way, ways_mod->way->name_room_way) == 0)
				{
					ways_all->mod = 2;
					ways_one->no_use = 1;
					ways_one->way->no_use = 1;
					ways_mod->no_use = 1;
					ways_mod->way->no_use = 1;
					return ;
				}
				ways_mod = ways_mod->way;
			}
			ways_mod = ways_tm_mod;
			ways_one = ways_one->way;
		}
		ways_all = ways_all->next_way;
	}
}

int		main(void)
{
	t_data_input	*data_input; 
	t_data			*data_lim;
	t_data_ways		*data_ways;
	t_data_ways		*data_ways_tm;
	int				count_way; // найти количество путей макс

	count_way = 0;
	data_input = new_data_inputlist(); // предварительный парсинг исходных данных в переменную 
	data_ways = new_ways_datalist();
	data_ways_tm = data_ways;
	// Получить данные из файла карты в листы 
	data_lim = get_data_input(data_input);
	count_way = data_lim->count_way / 2;
	//-----------------------------------

	bellamna_ford(data_lim->rooms, data_lim->links);
	data_ways->way = save_way(data_lim->rooms);
	//проверка пути/путей, но в цикле только
	
	//-----------------------------------
	//базовые настройки
	data_lim = base_setting(data_lim->rooms, data_lim->links, data_ways->way);
	//-----------------------------------
	data_ways->next_way = new_ways_datalist();
	data_ways = data_ways->next_way;

	while (count_way > 1) // ограничение на найденные пути необходимо ввести
	{
		//тест цикл начинается
		bellamna_ford(data_lim->rooms, data_lim->links);
		data_ways->way = save_new_way(data_lim->rooms, data_ways_tm, data_ways);
		if (data_ways->way == NULL) // если белман не нашел пути
			data_ways->bad_way = -1;
		if (data_ways->bad_way == 0 && data_ways->mod == 0)
		{// нет ни пересечений, ни модификаций пути, путь сохраняем
			data_lim = base_setting(data_lim->rooms, data_lim->links, data_ways->way);
			data_ways->next_way = new_ways_datalist();
			data_ways = data_ways->next_way;
			//count_way определять количество путей для цикла
		}
		if (data_ways->bad_way == 0 && data_ways->mod > 0)
		{// пересечений нет, есть модификация пути
		// собираем все пути после будем модифицировать если нет плохих путей
		// уже за циклом while
			ft_printf("hello world\n");
			mod_way(data_ways->way, data_ways_tm);
			//data_ways = data_ways_tm;
			data_lim = base_setting_mod(data_lim->rooms, data_lim->links, data_ways_tm);
			data_ways->next_way = new_ways_datalist();
			data_ways = data_ways->next_way;
			bellamna_ford(data_lim->rooms, data_lim->links);
			data_ways->way = save_way(data_lim->rooms);
			data_lim = base_setting(data_lim->rooms, data_lim->links, data_ways->way);
			data_ways->next_way = new_ways_datalist();
			data_ways = data_ways->next_way;
			bellamna_ford(data_lim->rooms, data_lim->links);
			data_ways->way = save_way(data_lim->rooms);
			data_lim = base_setting(data_lim->rooms, data_lim->links, data_ways->way);
			data_ways->next_way = new_ways_datalist();
			data_ways = data_ways->next_way;
		}
		if (data_ways->bad_way == 1)
		{// если есть пересечение, путь бракуем, что делать дальше решим
			data_lim = base_setting_bad_way(data_lim->rooms, data_lim->links, data_ways->way);
			ft_printf("gg\n");
			//приводить к базовым настройкам с учетом ребра заблоченого
			// !!!!!НАДО ОТЧИСТЬТЬ ПУТЬ КОТОРЫЙ НЕ НУЖЕН ПАМЯТЬ
			data_ways->way = NULL;
			data_ways->bad_way = 0;
		}
		count_way--;
	}
	
// движение муравьев по комнатам

	run_lim_run((ft_atoi(data_input->str)), data_ways_tm);

	return (0);
}	     