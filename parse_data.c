/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:24:08 by fprovolo          #+#    #+#             */
/*   Updated: 2020/10/30 00:14:01 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			count_ways(t_data_link *links)
{
	int			count;

	count = 0;
	while (links->next != NULL)
	{
		if (links->from_room->start == 1 || links->from_room->end == 1)
			count++;
		links = links->next;
	}
	return (count);
}

t_data		*union_room_link(t_data *data_lim)
{
	t_data_room *rooms;
	t_data_link *links;

	rooms = data_lim->rooms;
	links = data_lim->links;
	while (links->next != NULL)
	{
		while (rooms != NULL)
		{
			if (ft_strcmp(rooms->name, links->from) == 0)
				links->from_room = rooms;
			else if (ft_strcmp(rooms->name, links->to) == 0)
				links->to_room = rooms;
			if (links->from_room != NULL && links->to_room != NULL)
				break ;
			rooms = rooms->next;
		}
		rooms = data_lim->rooms;
		links = links->next;
	}
	data_lim->count_way = count_ways(data_lim->links);
	return (data_lim);
}

t_data_link	*parse_link(char *str, t_data_link *links, char *start, char *end)
{
	char		**room;
	t_data_link	*links_tmp;

	links_tmp = links;
	room = ft_strsplit(str, '-');
	links->from = room[0];
	links->to = room[1];
	links->next = new_data_linklist();
	links->next->from = room[1];
	links->next->to = room[0];
	if (ft_strcmp(room[0], start) == 0)
		links->next->act = 0;
	else if (ft_strcmp(room[1], start) == 0)
		links->act = 0;
	else if (ft_strcmp(room[0], end) == 0)
		links->act = 0;
	if (ft_strcmp(room[1], end) == 0)
		links->next->act = 0;
	return (links_tmp);
}

int			is_room(char **line)
{
	char		*ptr;

	if (line[0] == NULL || line[1] == NULL || line[2] == NULL
			|| line[3] != NULL)
		return (0);
	if (ft_strlen(line[0]) == 0 || ft_strlen(line[1]) == 0
			|| ft_strlen(line[2]) == 0)
		return (0);
	ptr = line[1];
	while (*ptr != '\0')
	{
		if (!(ft_isdigit(*ptr)))
			return (0);
		ptr++;
	}
	ptr = line[2];
	while (*ptr != '\0')
	{
		if (!(ft_isdigit(*ptr)))
			return (0);
		ptr++;
	}
	return (1);
}

t_data_room	*parse_room(char *str, int start_end, t_data_room *rooms_tmp)
{
	char		**line;
	int			i;

	line = ft_strsplit(str, ' ');
	if (!(is_room(line)))
	{
		ft_printf("%s : %s\n", str, "BAD FORMAT!");
		return (NULL);
	}
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
	rooms_tmp->name = line[0];
	rooms_tmp->coord_x = line[1];
	rooms_tmp->coord_y = line[2];
	return (rooms_tmp);
}

t_data		*parse_data(t_data_input *data_input)
{
	t_data_room	*rooms;
	t_data_link	*links;
	t_data		*data_lim;
	char		*start;
	char		*end;

	data_lim = new_datalist();
	rooms = data_lim->rooms;
	links = data_lim->links;
	start = NULL;
	end = NULL;
	data_input = data_input->next;
	while (data_input->str != NULL)
	{
		if (ft_strstr(data_input->str, "-") != NULL)
		{
			links = parse_link(data_input->str, links, start, end);
			links->next->next = new_data_linklist();
			links = links->next->next;
		}
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
	}
	// заводим комнаты под ссылки, каждая ссылка имеет связь с двумя комнатами
	data_lim = union_room_link(data_lim);
	return (data_lim);
}
