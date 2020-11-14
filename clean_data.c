/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:28:58 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/14 16:40:10 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		clean_data_rooms(t_data_room *rooms)
{
	t_data_room	*tmp;

	if (rooms != NULL)
	{
		while (rooms->next != NULL)
		{
			tmp = rooms;
			rooms = rooms->next;
			free(tmp->name);
			free(tmp->coord_x);
			free(tmp->coord_y);
			free(tmp);
		}
		free(rooms);
	}
}

static void		clean_data_links(t_data_link *links)
{
	t_data_link	*tmp;

	if (links != NULL)
	{
		while (links->next != NULL && links->next->next != NULL)
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

void			clean_way(t_ways *way)
{
	t_ways		*tmp;

	if (way != NULL)
	{
		while (way->way != NULL)
		{
			tmp = way;
			way = way->way;
			free(tmp);
		}
		free(way);
	}
}

static void		clean_dataways(t_data_ways *data_ways)
{
	t_data_ways		*dataway_tmp;

	if (data_ways != NULL)
	{
		while (data_ways->next_way != NULL)
		{
			dataway_tmp = data_ways;
			data_ways = data_ways->next_way;
			clean_way(dataway_tmp->way);
			free(dataway_tmp);
		}
		clean_way(data_ways->way);
		free(data_ways);
	}
}

void			clean_datalists(t_data *data_lim, t_data_input *data_input, \
				t_data_ways *data_ways)
{
	if (data_lim != NULL)
	{
		clean_data_input(data_input);
		clean_data_rooms(data_lim->rooms);
		clean_data_links(data_lim->links);
		clean_dataways(data_ways);
		free(data_lim);
	}
}
