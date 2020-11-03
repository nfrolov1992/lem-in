#include "lem_in.h"

//объеденяю комнат и ссылки в сылки
// t_data			*union_room_link(t_data *data_lim)
// {
// 	t_data_room *rooms;
// 	t_data_link *links;
// 	t_data_room *from;
// 	t_data_room *to;

// 	rooms = data_lim->rooms;
// 	links = data_lim->links;
// 	while (links->next != NULL)
// 	{
// 		while (rooms->next != NULL)
// 		{
// 			if (ft_strcmp(rooms->name, links->from) == 0)
// 			{
// 				from = rooms;
// 				links->from_room = from;
// 				links->next->to_room = from;
// 			}
// 			else if (ft_strcmp(rooms->name, links->to) == 0)
// 			{
// 				to = rooms;
// 				links->to_room = to;
// 				links->next->from_room = to;
// 			}
// 			if (links->from_room != NULL && links->to_room != NULL)
// 				break;
// 			rooms = rooms->next;
// 		}
// 		rooms = data_lim->rooms;
// 		links = links->next->next;
// 	}
// 	links = data_lim->links;
// 	while (links->next != NULL)
// 	{
// 		if (links->from_room->start == 1 || links->from_room->end == 1)
// 			data_lim->count_way++;
// 		links = links->next;
// 	}
// 	return (data_lim);
// }

// t_data_link		*parse_link(char *str, t_data *data_lim)
// {
// 	char			**line;
// 	t_data_link		*links;
// 	char			*l1;
// 	char			*l2;

// 	links = data_lim->links;
// 	line = ft_strsplit(str, '-');
// 	if (line[0] == NULL || line[1] == NULL || line[3] != NULL ||
// 			ft_strlen(line[0]) == 0 || ft_strlen(line[1]) == 0)
// 		terminate("Bad map: invalid link");

// 	l1 = *line;
// 	line++;
// 	l2 = *line;

// 	if (ft_strcmp(l1, start) == 0)
// 	{
// 		links->from = l1;
// 		links->to = l2;
// 		links->next = new_data_linklist();
// 		links = links->next;
// 		links->from = l2;
// 		links->to = l1;
// 		links->act = 0;
// 	}
// 	else if (ft_strcmp(l2, start) == 0)
// 	{
// 		links->from = l2;
// 		links->to = l1;
// 		links->next = new_data_linklist();
// 		links = links->next;
// 		links->from = l1;
// 		links->to = l2;
// 		links->act = 0;
// 	}
// 	else if (ft_strcmp(l1, end) == 0)
// 	{
// 		links->from = l2;
// 		links->to = l1;
// 		links->next = new_data_linklist();
// 		links = links->next;
// 		links->from = l1;
// 		links->to = l2;
// 		links->act = 0;
// 	}
// 	else if (ft_strcmp(l2, end) == 0)
// 	{
// 		links->from = l1;
// 		links->to = l2;
// 		links->next = new_data_linklist();
// 		links = links->next;
// 		links->from = l2;
// 		links->to = l1;
// 		links->act = 0;
// 	}
// 	else
// 	{
// 		links->from = l1;
// 		links->to = l2;
// 		links->next = new_data_linklist();
// 		links = links->next;
// 		links->from = l2;
// 		links->to = l1;
// 	}
	

// 	return (data_lim);
// }



static void		validate_room(char **line, t_data_room *rooms)
{
	if (line[1] == NULL || line[2] == NULL || line[3] != NULL)
		terminate("Bad map: wrong number of fields in room definition");
	if (ft_strlen(line[0]) == 0)
		terminate("Bad map: missing room name");
	if ((is_positive_int(line[1]) < 0) || (is_positive_int(line[2]) < 0))
	{
		ft_printf("%s %s %s\n", line[0], line[1], line[2]);
		terminate("Bad map: wrong room coordinates");
	}
	while (rooms->next != NULL)
	{
		if (ft_strcmp(rooms->name, line[0]) == 0)
			terminate("Bad map: room name duplicates");
		if (ft_strcmp(rooms->coord_x, line[1]) == 0 && ft_strcmp(rooms->coord_y, line[2]) == 0)
			terminate("Bad map: room coordinates duplicate");
		rooms = rooms->next;
	}
	return ;
}

static void			push_room(char *str, int start_end, t_data_room *rooms)
{
	char			**line;

	line = ft_strsplit(str, ' ');
	validate_room(line, rooms);
	while (rooms->next != NULL)
		rooms = rooms->next;
	rooms->name = line[0];
	rooms->coord_x = line[1];
	rooms->coord_y = line[2];
	if (start_end == 1)
	{
		rooms->start = 1;
		rooms->length = 0;
	}
	else if (start_end == 2)
	{
		rooms->end = 1;
	}
	rooms->next = new_data_roomlist();
	// rooms = rooms->next;
	// ft_printf("Room: %s, coord:%s %s\n", rooms_tmp->name, rooms_tmp->coord_x, rooms_tmp->coord_y);
	return ;
}

static t_data_input	*parse_rooms(t_data_input *data_input, t_data_room *room)
{
	while (data_input->str != NULL)
	{
		// не комментарий или левые команды
		if (!(data_input->str[0] == '#' && ft_strcmp(data_input->str, "##start") != 0 &&
			ft_strcmp(data_input->str, "##end") != 0))
		{
			// если встретили минус, идем в другой цикл парсить линки
			if (ft_strstr(data_input->str, "-") != NULL)
				return (data_input);
			// комнаты
			if (ft_strcmp(data_input->str, "##start") == 0)
			{
				data_input = data_input->next;
				push_room(data_input->str, 1, room);
			}
			else if (ft_strcmp(data_input->str, "##end") == 0)
			{
				data_input = data_input->next;
				push_room(data_input->str, 2, room);
			}
			else
				push_room(data_input->str, 0, room);
		}
		data_input = data_input->next;
	}
	return (data_input);
}

t_data			*parse_data(t_data_input *data_input)
{
	t_data_room		*room;
	t_data			*data_lim;
	char			*str;
	int				res;

	data_lim = new_datalist();
	room = data_lim->rooms;

	res = is_positive_int(data_input->str);
	ft_printf("*** int=%d ***\n", res);
	if (res < 1)
		terminate("Bad map: invalid lemin count");
	data_input = parse_rooms(data_input->next, data_lim->rooms);
	// parse_links(data_input, data_lim);

	// // заводим комнаты под ссылки, каждая ссылка имеет связь с двумя комнатами
	// data_lim = union_room_link(data_lim);
	print_farm(data_lim);
	return (data_lim);
}
