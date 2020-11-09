/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:28:58 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/09 14:25:48 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		clean_data_input(t_data_input *data_input)
{
	t_data_input	*tmp;

	while (data_input->next != NULL)
	{
		free(data_input->str);
		tmp = data_input;
		data_input = data_input->next;
		free(tmp);
	}
}

static void		clean_data_rooms(t_data_room *rooms)
{
	t_data_room	*room_del;

	if (rooms != NULL)
	{
		while(rooms->next != NULL)
		{
			room_del = rooms;
			rooms = rooms->next;
			free(room_del->name);
			free(room_del->coord_x);
			free(room_del->coord_y);
			free(room_del);
		}
		free(rooms);
	}
}

static void		clean_data_links(t_data_link *links)
{
	t_data_link	*tmp;

	if (links != NULL)
	{
		while(links->next != NULL && links->next->next != NULL)
		{
			tmp = links;
			links = links->next->next;
			free(tmp->from);
			free(tmp->to);
			free(tmp->next);
			free(tmp);
		}
		free(links);
	}
}

void    clean_datalists(t_data *data_lim, t_data_input *data_input)
{
	if (data_lim != NULL)
	{
		clean_data_input(data_input);
		clean_data_rooms(data_lim->rooms);
		clean_data_links(data_lim->links);
		free(data_lim);
	}
}
