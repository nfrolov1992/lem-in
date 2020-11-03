#include "lem_in.h"

t_data_input	*new_data_inputlist(void)
{
	t_data_input *new;

	if ((new = (t_data_input *)malloc(sizeof(t_data_input))))
	{
		new->str = NULL;
		new->next = NULL;
	}
	return (new);
}

t_data_room	*new_data_roomlist(void)
{
	t_data_room *new;

	if ((new = (t_data_room *)malloc(sizeof(t_data_room))))
	{
		new->name = NULL;
		new->start = 0;
		new->end = 0;
		new->length = 2000000000;
		new->use_room = 0;
		new->from_link = NULL;
		new->coord_x = NULL;
		new->coord_y = NULL;
		new->next = NULL;
	}
	return (new);
}

t_data_link	*new_data_linklist(void)
{
	t_data_link *new;

	if ((new = (t_data_link *)malloc(sizeof(t_data_link))))
	{
		new->from = NULL;
		new->from_room = NULL;
		new->to = NULL;
		new->to_room = NULL;
		new->weight = 1;
		new->act = 1;
		new->count_way = 0;
		new->next = NULL;
	}
	return (new);
}

t_data	*new_datalist(void)
{
	t_data *new;

	if ((new = (t_data *)malloc(sizeof(t_data))))
	{
		new->rooms = new_data_roomlist();
		new->links = new_data_linklist();
		new->count_way = 0;
	}
	return (new);
}

t_data_ways	*new_ways_datalist(void)
{
	t_data_ways *new;

	if ((new = (t_data_ways *)malloc(sizeof(t_data_ways))))
	{
		new->length_way = 0;
		new->first_way = 0;
		new->way = NULL;
		new->next_way = NULL;
		new->prev_way = NULL;
	}
	return (new);
}

t_ways	*new_wayslist(void)
{
	t_ways *new;

	if ((new = (t_ways *)malloc(sizeof(t_ways))))
	{
		new->name_room_way = NULL;
		new->name_lim = NULL;
		new->length_way = 0;
		new->end = 0;
		new->no_use = 0;
		new->way = NULL;
		new->start = 0;
		new->lim = 0;
		new->way_prev = NULL;
	}
	return (new);
}
