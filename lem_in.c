#include "lem_in.h"

static int		search_count_way(t_data *data_lim)
{
	int				i;
	t_data_link		*links_tm;

	i = 0;
	links_tm = data_lim->links;
	while (links_tm->next != NULL)
	{
		if (links_tm->from_room->start == 1 && links_tm->to_room->end != 1)
			i++;
		else if (links_tm->from_room->start == 1 && links_tm->to_room->end == 1)
			i++;
		links_tm = links_tm->next;
	}
	return (i);
}

static t_data	*new_graph(t_data_room *rooms, t_data_link *links, t_data_ways *ways, t_data *data_lim)
{
	t_data_room		*rooms_tm;
	t_data_link		*links_tm;
	t_data_ways		*ways_tm;
	// t_data			*data_lim;

	rooms_tm = rooms;
	links_tm = links;
	ways_tm = ways;
	// data_lim = new_datalist();
	while (links->next != NULL)
	{
		if (links->count_way == 1)
			links->act = 1;
			
		else if (links->count_way == 0)
			links->act = 0;
		links->weight = 1;
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
	links = links_tm;
	int	a = 0;
	while (links->next != NULL)
	{
		if (links->count_way == links->next->count_way && links->count_way == 1)
		{
			links->act = 0;
			links->next->act = 0;
			a++;
		}
		else if (links->to_room->start == 1)
			links->act = 0;
		else if (links->from_room->end == 1)
			links->act = 0;
		else
		{
			links->act = 1;
			links->next->act = 1;
		}
		links = links->next->next;
	}
	data_lim->rooms = rooms_tm;
	data_lim->links = links_tm;

	return (data_lim);
}

static t_data	*base_setting_bah(t_data_room *rooms, t_data_link *links, t_ways *ways)
{
	t_data_room		*rooms_tm;
	t_data_link		*links_tm;
	t_ways			*ways_tm;
	t_data			*data_lim;

	rooms_tm = rooms;
	links_tm = links;
	ways_tm = ways;
	data_lim = new_datalist();
	while (links->next != NULL)
	{
		while (ways->way->name_room_way != NULL)
		{
			if (ways->name_room_way != NULL && ft_strcmp(ways->name_room_way, links->from) == 0 && ft_strcmp(ways->way->name_room_way, links->to) == 0)
			{
				links->weight = -1;
				links->act = 1;
			}
			//нашли маршрут который надо выключить он не действует более
			else if (ways->name_room_way != NULL && ft_strcmp(ways->name_room_way, links->to) == 0 && ft_strcmp(ways->way->name_room_way, links->from) == 0)
			{
				links->act = 0;
				links->count_way = 1;
			}
			ways = ways->way;
		}
		ways = ways_tm;
		if (links->to_room->start == 1)
			links->act = 0;
		if (links->from_room->end == 1)
			links->act = 0;
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
	return (data_lim);
}

static t_data			*get_bhandari(t_data *data_lim)
{
	t_data_ways		*data_ways;
	t_data_ways		*data_ways_tm;
	int				i;

	data_ways = new_ways_datalist();
	data_ways_tm = data_ways;
	
	i = search_count_way(data_lim);
	
	while (i > 5)
	{
		bellamna_ford(data_lim->rooms, data_lim->links);
		data_ways->way = save_way(data_lim->rooms);  
		if (data_ways->way == NULL)
			break ;
		data_ways->length_way = data_ways->way->length_way - 1;
		data_lim = base_setting_bah(data_lim->rooms, data_lim->links, data_ways->way);
		data_ways->next_way = new_ways_datalist();
		data_ways->next_way->prev_way = data_ways;
		data_ways = data_ways->next_way;
		i--;
	}

	data_lim = new_graph(data_lim->rooms, data_lim->links, data_ways_tm, data_lim);

	return (data_lim);
}

static t_data_ways		*go_search_way(t_data *data_lim, t_data_ways *data_ways, int count_way)
{
	t_data_ways		*data_ways_tm;
	int				i;
	data_ways_tm = data_ways;

	i = search_count_way(data_lim);

	while (i > 37)
	{
		bellamna_ford(data_lim->rooms, data_lim->links);
		data_ways->way = save_way(data_lim->rooms);  
		if (data_ways->way == NULL)
			break;
		data_ways->length_way = data_ways->way->length_way - 1;
		data_lim = base_setting(data_lim->rooms, data_lim->links, data_ways->way, data_lim);
		data_ways->next_way = new_ways_datalist();
		data_ways->next_way->prev_way = data_ways;
		data_ways = data_ways->next_way;
		count_way--;
		i--;
	}
	return (data_ways_tm);
}

int						main(void)
{
	t_data_input	*data_input;
	t_data			*data_lim;
	t_data_ways		*data_ways;

	data_input = new_data_inputlist();
	data_ways = new_ways_datalist();
	data_lim = get_data_input(data_input);
	data_lim = get_bhandari(data_lim);
	data_ways = go_search_way(data_lim, data_ways, (data_lim->count_way / 2));
	data_ways = mod_ways(data_ways);
	if (data_ways->way != NULL)
	{
		ft_printf("\n");
		run_lim_run((ft_atoi(data_input->str)), data_ways);
		ft_printf("\n");
		exit(0);
	}
	else
		ft_printf("Пути НЕТ!!!!!!!!!!");
	return (0);
}	     
