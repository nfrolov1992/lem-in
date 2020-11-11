/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:43:34 by fprovolo          #+#    #+#             */
/*   Updated: 2020/11/08 14:48:30 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_data_ways	*new_ways_datalist(void)
{
	t_data_ways *new;

	if ((new = (t_data_ways *)malloc(sizeof(t_data_ways))))
	{
		new->length_way = 0;
		new->first_way = 0;
		new->way = NULL;
		new->next_way = NULL;
		new->prev_way = NULL;
	}
	return (new);
}

t_ways		*new_wayslist(void)
{
	t_ways *new;

	if ((new = (t_ways *)malloc(sizeof(t_ways))))
	{
		new->name_room_way = NULL;
		new->name_lim = NULL;
		new->length_way = 0;
		new->end = 0;
		new->no_use = 0;
		new->way = NULL;
		new->start = 0;
		new->lim = 0;
		new->way_prev = NULL;
	}
	return (new);
}
