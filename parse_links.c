/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:08:10 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/03 19:18:02 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// объеденяю комнат и ссылки в сылки
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

// int         check_room_presence(t_data_room *rooms, char *from, char *to)
// {
// 	int     room_found;
// 	int     disable;

// 	room_found = 0;
// 	disable = 0;
// 	while (rooms->next != NULL)
// 	{
// 		if (ft_strcmp(rooms->name, from == 0))
// 		{
// 			room_found++;
// 			if (rooms->start == 1)
// 				disable = 2; // отключить обратку
// 			else if (rooms->end == 1)
// 				disable = 1; // отключить
// 		}
// 		if (ft_strcmp(rooms->name, from == 0))
// 		{
// 			room_found++;
// 			if(rooms->start == 1)
// 				disable = 2; // отключить обратку
// 			elseif(rooms->end == 1)
// 				from = 2
// 		}
// 		rooms = rooms->next;
// 	}
// }


t_data_input	*parse_links(t_data_input *data_input, t_data *data_lim)
{
	char        **line;
	t_data_link	*links;
	// t_data_room *rooms;

	links = data_lim->links;
	while (data_input->str != NULL)
	{
		if (ft_strcmp(data_input->str, "##start") == 0 || ft_strcmp(data_input->str, "##end") == 0)
			terminate("Bad map: Start/End command in link area");
		if (!(data_input->str[0] == '#'))
		{
			line = ft_strsplit(data_input->str, '-');
			if (line[0] == NULL || line[1] == NULL || line[3] != NULL)
				terminate("Bad map: invalid link format");
			if (ft_strcmp(line[0], line[1]) == 0)
				terminate("Bad map: link source and target are same");
			links->from = line[0];
			links->to = line[1];
			links->next = new_data_linklist();
			links = links->next;
			links->from = line[1];
			links->to = line[0];
			links->next = new_data_linklist();
			links = links->next;
		}
		data_input = data_input->next;
	}
	return (data_input);
}
