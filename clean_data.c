/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:28:58 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/08 19:16:45 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void    clean_data_rooms(t_data_room *rooms)
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

static void    clean_data_links(t_data_link *links)
{
	t_data_link	*link_del;

	if (links != NULL)
	{
		while(links->next != NULL)
		{
			link_del = links;
			links = links->next;
			free(link_del->from);
			free(link_del->to);
			free(link_del);
		}
		// free(links);
	}
}

void    clean_datalist(t_data *data_lim)
{
	if (data_lim != NULL)
	{
		clean_data_rooms(data_lim->rooms);
		// clean_data_links(data_lim->links);
		free(data_lim);
	}
}
