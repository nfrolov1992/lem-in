/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:51:06 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/14 14:15:16 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			check_start_end(t_data_room *rooms)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (rooms->next != NULL)
	{
		start += rooms->start;
		end += rooms->end;
		rooms = rooms->next;
	}
	if (start != 1 || end != 1)
		terminate("ERROR\nStart/End missing or duplicates");
	return ;
}

static void			validate_room(char **line, t_data_room *rooms)
{
	if (line[1] == NULL || line[2] == NULL || line[3] != NULL)
		terminate("ERROR\nWrong number of fields in room definition");
	if (ft_strlen(line[0]) == 0)
		terminate("ERROR\nMissing room name");
	if (line[0][0] == 'L')
		terminate("ERROR\nIncorrect room name starts with L");
	if (!(is_good_int(line[1])) || !(is_good_int(line[2])))
		terminate("ERROR\nWrong room coordinates - must be integer");
	while (rooms->next != NULL)
	{
		if (ft_strequ(rooms->name, line[0]))
			terminate("ERROR\nRoom name duplicates");
		if (ft_strequ(rooms->coord_x, line[1]) &&
			ft_strequ(rooms->coord_y, line[2]))
			terminate("ERROR\nRoom coordinates duplicate");
		rooms = rooms->next;
	}
	return ;
}

static void			push_room(char *str, int start_end, t_data_room *rooms)
{
	char	**line;

	line = ft_strsplit(str, ' ');
	validate_room(line, rooms);
	while (rooms->next != NULL)
		rooms = rooms->next;
	rooms->name = line[0];
	rooms->coord_x = line[1];
	rooms->coord_y = line[2];
	free(line);
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
	return ;
}

static t_data_input	*parse_rooms(t_data_input *data_input, t_data_room *rooms)
{
	while (data_input->str != NULL)
	{
		if (!(data_input->str[0] == '#' &&
			!ft_strequ(data_input->str, "##start") &&
			!ft_strequ(data_input->str, "##end")))
		{
			if (looks_like_link(data_input->str))
				return (data_input);
			if (ft_strequ(data_input->str, "##start"))
			{
				data_input = data_input->next;
				push_room(data_input->str, 1, rooms);
			}
			else if (ft_strequ(data_input->str, "##end"))
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

t_data				*parse_data(t_data_input *data_input)
{
	t_data			*data_lim;

	data_lim = NULL;
	data_lim = new_datalist();
	if (is_positive_int(data_input->str) < 1)
		terminate("ERROR\nAnts count must be positive int at first line");
	data_input = parse_rooms(data_input->next, data_lim->rooms);
	check_start_end(data_lim->rooms);
	parse_links(data_input, data_lim);
	return (data_lim);
}
