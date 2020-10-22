#include "lem_in.h"

//объеденяю комнат и ссылки в сылки
t_data			*union_room_link(t_data_room *rooms, t_data_link *links)
{
	t_data_room *room_tmp;
	t_data_link *links_tmp;
	t_data_room *from;
	t_data_room *to;
	t_data		*data_lim;

	room_tmp = rooms;
	links_tmp = links;
	data_lim = new_datalist();
	while (links->next != NULL)
	{
		while (rooms->next != NULL)
		{
			if (ft_strcmp(rooms->name, links->from) == 0)
			{
				from = rooms;
				links->from_room = from;
				links->next->to_room = from;
			}
			else if (ft_strcmp(rooms->name, links->to) == 0)
			{
				to = rooms;
				links->to_room = to;
				links->next->from_room = to;
			}
			if (links->from_room != NULL && links->to_room != NULL)
				break;
			rooms = rooms->next;
		}
		rooms = room_tmp;
		links = links->next->next;
	}
	links = links_tmp;
	while (links->next != NULL)
	{
		if (links->from_room->start == 1 || links->from_room->end == 1)
			data_lim->count_way++;
		links = links->next;
	}
	data_lim->rooms = room_tmp;
	data_lim->links = links_tmp;
	return (data_lim);
}

t_data_link		*parse_link(char *str, t_data_link *links, char *start, char *end)
{
	char			**line;
	t_data_link		*links_tmp;
	char			*l1;
	char			*l2;

	links_tmp = links;
	line = ft_strsplit(str, '-');

	l1 = *line;
	line++;
	l2 = *line;

	if (ft_strcmp(l1, start) == 0)
	{
		links->from = l1;
		links->to = l2;
		links->next = new_data_linklist();
		links = links->next;
		links->from = l2;
		links->to = l1;
		links->act = 0;
	}
	else if (ft_strcmp(l2, start) == 0)
	{
		links->from = l2;
		links->to = l1;
		links->next = new_data_linklist();
		links = links->next;
		links->from = l1;
		links->to = l2;
		links->act = 0;
	}
	else if (ft_strcmp(l1, end) == 0)
	{
		links->from = l2;
		links->to = l1;
		links->next = new_data_linklist();
		links = links->next;
		links->from = l1;
		links->to = l2;
		links->act = 0;
	}
	else if (ft_strcmp(l2, end) == 0)
	{
		links->from = l1;
		links->to = l2;
		links->next = new_data_linklist();
		links = links->next;
		links->from = l2;
		links->to = l1;
		links->act = 0;
	}
	else
	{
		links->from = l1;
		links->to = l2;
		links->next = new_data_linklist();
		links = links->next;
		links->from = l2;
		links->to = l1;
	}
	

	return (links_tmp);
}

t_data_room		*parse_room(char *str, int start_end, t_data_room *rooms_tmp)
{
	char			**line;
	int				i;

	line = ft_strsplit(str, ' ');
	i = 0;
	if (start_end == 1)
	{
		rooms_tmp->start = 1;
		rooms_tmp->length = 0;
	}
	else if (start_end == 2)
	{
		rooms_tmp->end = 1;
	}
	while (i < 3)
	{
		if (i == 0)
			rooms_tmp->name = *line;
		else if (i == 1)
			rooms_tmp->coord_x = *line;
		else
			rooms_tmp->coord_y = *line;
		line++;
		i++;
	}
	return (rooms_tmp);
}

t_data			*parse_data(t_data_input *data_input)
{
	t_data_room		*rooms;
	t_data_room		*rooms_tm;

	t_data_link		*links;
	t_data_link		*links_tm;

	t_data			*data_lim;

	char			*start;
	char			*end;

	rooms = new_data_roomlist();
	rooms_tm = rooms;
	links = new_data_linklist();
	links_tm = links;
	start = NULL;
	end = NULL;

	data_input = data_input->next;

	while (data_input->str != NULL)
	{
		// рассматриваем ссылки
		if (ft_strstr(data_input->str, "-") != NULL)
		{
			links = parse_link(data_input->str, links, start, end);
			links->next->next = new_data_linklist();
			links = links->next->next;
		}
		// расматриваем комнаты
		else if (ft_strcmp(data_input->str, "##start") == 0 || ft_strcmp(data_input->str, "##end") == 0)
		{
			if (ft_strcmp(data_input->str, "##start") == 0)
			{
				rooms = parse_room(data_input->next->str, 1, rooms);
				start = rooms->name;
			}
			else if (ft_strcmp(data_input->str, "##end") == 0)
			{
				rooms = parse_room(data_input->next->str, 2, rooms);
				end = rooms->name;
			}
			data_input = data_input->next;
			rooms->next = new_data_roomlist();
			rooms = rooms->next;
		}
		else
		{//средние комнаты
			rooms = parse_room(data_input->str, 0, rooms);
			rooms->next = new_data_roomlist();
			rooms = rooms->next;
		}
		data_input = data_input->next;
	}//парсинг завершон

	// заводим комнаты под ссылки, каждая ссылка имеет связь с двумя комнатами
	data_lim = union_room_link(rooms_tm, links_tm);
	return (data_lim);
}
