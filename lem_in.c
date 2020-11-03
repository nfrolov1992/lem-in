#include "lem_in.h"

static t_data_ways		*go_search_way(t_data *data_lim, t_data_ways *data_ways, int count_way)
{
	t_data_ways		*data_ways_tm;

	data_ways_tm = data_ways;
	while (count_way != 0)
	{
		bellamna_ford(data_lim->rooms, data_lim->links);
		data_ways->way = save_way(data_lim->rooms);  
		if (data_ways->way == NULL)
			break;
		data_ways->length_way = data_ways->way->length_way - 1;
		data_lim = base_setting(data_lim->rooms, data_lim->links, data_ways->way);
		data_ways->next_way = new_ways_datalist();
		data_ways->next_way->prev_way = data_ways;
		data_ways = data_ways->next_way;
		count_way--;
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
	// data_ways = go_search_way(data_lim, data_ways, (data_lim->count_way / 2));
	// if (data_ways->way != NULL)
	// 	run_lim_run((ft_atoi(data_input->str)), data_ways);
	// else
	// 	ft_printf("Пути НЕТ!!!!!!!!!!");
	return (0);
}	     
