/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:08:10 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/12 20:27:03 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			count_ways(t_data *data_lim)
{
	t_data_link		*links;

	links = data_lim->links;
	while (links->next != NULL)
	{
		if (links->from_room->start == 1 || links->from_room->end == 1)
			data_lim->count_way++;
		links = links->next;
	}
	return ;
}

static void			union_room_link(t_data_link *link, t_data_room *rooms)
{
	while (rooms->next != NULL)
	{
		if (ft_strequ(rooms->name, link->from))
		{
			link->from_room = rooms;
			link->next->to_room = rooms;
			if (rooms->start)
				link->next->act = 0;
			else if (rooms->end)
				link->act = 0;
		}
		if (ft_strequ(rooms->name, link->to))
		{
			link->to_room = rooms;
			link->next->from_room = rooms;
			if (rooms->start)
				link->act = 0;
			else if (rooms->end)
				link->next->act = 0;
		}
		rooms = rooms->next;
	}
	if (link->from_room == NULL || link->to_room == NULL)
		terminate("ERROR\nNon-existing room in link line");
	return ;
}

static t_data_link	*add_link(t_data_link *links, t_data_room *rooms,
					char **line)
{
	links->from = line[0];
	links->to = line[1];
	links->next = new_data_linklist();
	links->next->from = line[1];
	links->next->to = line[0];
	links->next->next = new_data_linklist();
	free(line);
	union_room_link(links, rooms);
	return (links->next->next);
}

void				parse_links(t_data_input *data_input, t_data *data_lim)
{
	char			**line;
	t_data_link		*links;

	links = data_lim->links;
	while (data_input->str != NULL)
	{
		if (ft_strequ(data_input->str, "##start") ||
			ft_strequ(data_input->str, "##end"))
			terminate("ERROR\nStart/End command in link area");
		if (!(data_input->str[0] == '#'))
		{
			line = ft_strsplit(data_input->str, '-');
			if (line[0] == NULL || line[1] == NULL || line[2] != NULL)
				terminate("ERROR\nInvalid link format");
			if (ft_strequ(line[0], line[1]))
				terminate("ERROR\nLink source and target are same");
			links = add_link(links, data_lim->rooms, line);
		}
		data_input = data_input->next;
	}
	if (data_lim->links->from == NULL)
		terminate("ERROR\nNo links were founded");
	count_ways(data_lim);
	return ;
}
