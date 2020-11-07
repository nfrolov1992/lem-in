#include "lem_in.h"


static void		check_start_end(t_data_room *rooms)
{
	int			start;
	int			end;

	start = 0;
	end = 0;
	while (rooms->next != NULL)
	{
		start += rooms->start;
		end += rooms->end;
		rooms = rooms->next;
	}
	if (start != 1 || end != 1)
		terminate("Bad map. Start/End missing or duplicates");
	return ;
}

static void		validate_room(char **line, t_data_room *rooms)
{
	if (line[1] == NULL || line[2] == NULL || line[3] != NULL)
		terminate("Bad map: wrong number of fields in room definition");
	if (ft_strlen(line[0]) == 0)
		terminate("Bad map: missing room name");
	if (line[0][0] == 'L')
		terminate("Bad map: incorrect room name starts with L");
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

static t_data_input	*parse_rooms(t_data_input *data_input, t_data_room *rooms)
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
				push_room(data_input->str, 1, rooms);
			}
			else if (ft_strcmp(data_input->str, "##end") == 0)
			{
				data_input = data_input->next;
				push_room(data_input->str, 2, rooms);
			}
			else
				push_room(data_input->str, 0, rooms);
		}
		data_input = data_input->next;
	}
	return (data_input);
}

t_data			*parse_data(t_data_input *data_input)
{
	t_data			*data_lim;
	char			*str;
	int				res;

	data_lim = new_datalist();
	res = is_positive_int(data_input->str);
	ft_printf("*** Ants: %d ***\n", res);
	if (res < 1)
		terminate("Bad map: ants count must be positive int at first line");
	data_input = parse_rooms(data_input->next, data_lim->rooms);
	check_start_end(data_lim->rooms);
	parse_links(data_input, data_lim);

	// // заводим комнаты под ссылки, каждая ссылка имеет связь с двумя комнатами
	// data_lim = union_room_link(data_lim);
	print_farm(data_lim);
	return (data_lim);
}
